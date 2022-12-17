/**
 * @file buttonModule.c
 * @author Augustin Jose
 * @brief This file contains all the function for initializing buttons, 
 * connecting and running event handlers. A linked list is maintained 
 * for cycling through all the registered buttons
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "buttonModule.h"
#include "buttonConfig.h"
#include <assert.h>
#include <stddef.h>

#define __IS_BUTTON_PRESS_ENUM_VALID__(x)               ((x >= BUTTON_NO_PRESS) && (x < BUTTON_PRESS_COUNT))
#define __iS_SHORT_PRESS_TIME_EXPIRED__(a_handle)       ((a_handle->tickCount >= (BUTTON_SINGLE_PRESS_PERIOD / BUTTON_TIMER_TICK_PERIOD)))
#define __IS_MULTI_PRESS_DELAY_TIME_EXPIRED__(a_handle) ((a_handle->tickCount >= (BUTTON_MULTI_PRESS_DELAY / BUTTON_TIMER_TICK_PERIOD)))
#define __RUN_EVENT_CALLBACK__(a_handle, a_event)       if(a_handle->callbackList[a_event] != NULL) \
                                                        { \
                                                            a_handle->callbackList[a_event](a_handle->argptr); \
                                                        } 


static void runButtonStateMachine(Button_t *a_handle);

/* Public functions.................................................................. */

/**
 * @brief To initialize the buttons with their GPIO pins
 * 
 * @param a_handle Button handle
 * @param a_pin GPIO pin
 * @param a_fnptr Pointer to the function to get GPIO pin state
 * @param a_args Pointer to arguments that needed to passed to the callback function
 */
void Button_Init(Button_t *a_handle, gpioPin a_pin, GpioState_t a_fnptr, void *a_args)
{
    _Static_assert(BUTTON_TIMER_TICK_PERIOD, "BUTTON_TIMER_TICK_PERIOD not configured!");
    _Static_assert(BUTTON_SINGLE_PRESS_PERIOD, "BUTTON_SINGLE_PRESS_PERIOD not configured!");
    _Static_assert(BUTTON_MULTI_PRESS_DELAY, "BUTTON_MULTI_PRESS_DELAY not configured!");

    assert((a_handle != NULL));
    assert((a_fnptr != NULL));
 
    a_handle->pin = a_pin;
    a_handle->pinState = BUTTON_NOT_PRESSED;
    a_handle->state = BUTTON_IDLE;
    a_handle->tickCount = 0;
    a_handle->getGpioPinState = a_fnptr;
    a_handle->nextInList = NULL;
    a_handle->argptr = a_args;
    for(int i = 0; i < BUTTON_PRESS_COUNT; i++)
    {
        a_handle->callbackList[i] = NULL;
    }
}

/**
 * @brief To connect a button press event to its event handler
 * 
 * @param a_handle Button handle
 * @param a_event Button press enum
 * @param a_eventHandle Pointer to the event handler
 */
void Button_ConnectEvent(Button_t *a_handle, ButtonPress_t a_event, EventHandler_t a_eventHandle)
{
    assert((a_handle != NULL));
    assert((__IS_BUTTON_PRESS_ENUM_VALID__(a_event)));
    assert((a_eventHandle != NULL));

    a_handle->callbackList[a_event] = a_eventHandle;
}

/**
 * @brief To disconnect an event handler from its event handler
 * 
 * @param a_handle Button handle
 * @param a_event Button press enum
 */
void Button_DisconnectEvent(Button_t *a_handle, ButtonPress_t a_event)
{
    assert((a_handle != NULL));
    assert((!__IS_BUTTON_PRESS_ENUM_VALID__(a_event)));
    
    a_handle->callbackList[a_event] = NULL;
}

/**
 * @brief To initialize the linked list of buttons
 * 
 * @param a_list Button list handle
 */
void Button_InitializeList(ButtonList_t *a_list)
{
    assert((a_list != NULL));
    a_list->buttonCount = 0;
    a_list->start = NULL;
    a_list->end = NULL;

}

/**
 * @brief To add a button to the linked list
 * 
 * @param a_list Button list handle
 * @param a_handle Button handle
 */
void Button_AddToList(ButtonList_t *a_list, Button_t *a_handle)
{
    assert((a_list != NULL));
    assert((a_handle != NULL));

    if(a_list->buttonCount == 0)
    {
        a_list->start = a_handle;
        a_list->end = a_handle;
    }
    else 
    {
        a_list->end->nextInList = a_handle;
        a_list->end = a_handle;
    }
    
    a_list->buttonCount++;
}

/**
 * @brief To periodically run the state machine for all the buttons in the linked list
 * 
 * @param a_list Button list handle
 * @note Frequency of this function call is defined by BUTTON_TIMER_TICK_PERIOD 
 */
void Button_PeriodicTask(ButtonList_t *a_list)
{
    // assert!

    Button_t *button;
    for(button = a_list->start; button != NULL; button = button->nextInList)
    {
        runButtonStateMachine(button);
    }
}

/* Private functions................................................................... */

/**
 * @brief State machine controlling the internal states of each buttons
 * 
 * @param a_handle Button handle
 */
static void runButtonStateMachine(Button_t *a_handle)
{
    ButtonState_t pinState = a_handle->getGpioPinState(a_handle->pin);

    if(a_handle->state != BUTTON_IDLE)
    {
        a_handle->tickCount++;
    }

    switch(a_handle->state)
    {
        case BUTTON_IDLE:
        if(pinState == BUTTON_PRESSED)
        {
            a_handle->state = BUTTON_FIRST_PRESS;
            a_handle->tickCount = 0;
        }
        break;
        case BUTTON_FIRST_PRESS:
        if(pinState == BUTTON_NOT_PRESSED)
        {
            if(!__iS_SHORT_PRESS_TIME_EXPIRED__(a_handle))
            {
                a_handle->state = BUTTON_FIRST_RELEASE;
                a_handle->tickCount = 0;
            }
            else
            {
                a_handle->state = BUTTON_LONG_RELEASE;
            }
        } 
        break;
        case BUTTON_FIRST_RELEASE:
        if(__IS_MULTI_PRESS_DELAY_TIME_EXPIRED__(a_handle))
        {
            __RUN_EVENT_CALLBACK__(a_handle, BUTTON_SINGLE_PRESS);
            a_handle->state = BUTTON_IDLE;
            a_handle->tickCount = 0;
        }
        else
        {
            if(pinState == BUTTON_PRESSED)
            {
                a_handle->state = BUTTON_SECOND_PRESS;
            }
        }
        break;
        case BUTTON_SECOND_PRESS:
        if(pinState == BUTTON_NOT_PRESSED)
        {
            a_handle->state = BUTTON_SECOND_RELEASE;
            a_handle->tickCount = 0;
        }
        break;
        case BUTTON_SECOND_RELEASE:
        if(__IS_MULTI_PRESS_DELAY_TIME_EXPIRED__(a_handle))
        {
            __RUN_EVENT_CALLBACK__(a_handle, BUTTON_DOUBLE_PRESS);
            a_handle->state = BUTTON_IDLE;
            a_handle->tickCount = 0;
        }
        else
        {
            if(pinState == BUTTON_PRESSED)
            {
                a_handle->state = BUTTON_THIRD_PRESS;
            }
        }
        break;
        case BUTTON_THIRD_PRESS:
        if(pinState == BUTTON_NOT_PRESSED)
        {
            a_handle->state = BUTTON_THIRD_RELEASE;
            a_handle->tickCount = 0;
        }
        break;
        case BUTTON_THIRD_RELEASE:
        __RUN_EVENT_CALLBACK__(a_handle, BUTTON_TRIPLE_PRESS);
        a_handle->state = BUTTON_IDLE;
        a_handle->tickCount = 0;
        break;
        case BUTTON_LONG_RELEASE:
        __RUN_EVENT_CALLBACK__(a_handle, BUTTON_LONG_PRESS);
        a_handle->state = BUTTON_IDLE;
        a_handle->tickCount = 0;
        break;
        default:
        break;
    }

    a_handle->pinState = pinState;
    
}   