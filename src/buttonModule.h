/**
 * @file buttonModule.h
 * @author Augustin Jose
 * @brief This header file contains all the enums, structs 
 * and prototypes of functions used in buttonModule
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BUTTONMODULE_H_
#define _BUTTONMODULE_H_

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t gpioPin;

/* Enumerations.........................................................................................................................*/
typedef enum{
    BUTTON_NO_PRESS = 0,                                        /* Default state of button                                              */
    BUTTON_SINGLE_PRESS,                                        /* Button single press event                                            */
    BUTTON_DOUBLE_PRESS,                                        /* Button double press event                                            */
    BUTTON_TRIPLE_PRESS,                                        /* Button triple press event                                            */
    BUTTON_LONG_PRESS,                                          /* Button long press event                                              */
    BUTTON_PRESS_COUNT,                                         /* Button event count                                                   */
}ButtonPress_t;

typedef enum{
    BUTTON_NOT_PRESSED = false,                                 /* Button released state                                                */
    BUTTON_PRESSED = true,                                      /* Button pressed state                                                 */
}ButtonState_t;

typedef enum{
    BUTTON_IDLE = 0,                                            /* Button idle state                                                    */
    BUTTON_FIRST_PRESS,                                         /* Button first press detected                                          */
    BUTTON_FIRST_RELEASE,                                       /* Button first release detected                                        */
    BUTTON_SECOND_PRESS,                                        /* Button second press detected                                         */
    BUTTON_SECOND_RELEASE,                                      /* Button second release detected                                       */
    BUTTON_THIRD_PRESS,                                         /* Button third press detected                                          */
    BUTTON_THIRD_RELEASE,                                       /* Button third release detected                                        */
    BUTTON_LONG_RELEASE,                                        /* Button long release detected                                         */
}ButtonTrigger_t;

/* Function pointer definitions.........................................................................................................*/
typedef bool (*GpioState_t)(gpioPin);
typedef void (*EventHandler_t)(void*);

/* Structure definitions................................................................................................................*/
typedef struct Button_t{
    gpioPin pin;                                                /* GPIO pin enumeration                                                 */
    ButtonState_t pinState;                                     /* Pin state                                                            */
    ButtonTrigger_t state;                                      /* Button state                                                         */
    uint32_t tickCount;                                         /* Value of internal counter                                            */
    GpioState_t getGpioPinState;                                /* Pointer to the function to return GPIO pin state                     */
    EventHandler_t callbackList[BUTTON_PRESS_COUNT];            /* List of event handlers                                               */
    struct Button_t *nextInList;                                /* Pointer to the next button in the list                               */
    void *argptr;                                               /* Pointer to the optional argument to be passed in the event handler   */
}Button_t;

typedef struct{
    Button_t *start;                                            /* Pointer to the first button handle                                   */
    Button_t *end;                                              /* Pointer to the last button handle                                    */
    uint32_t buttonCount;                                       /* Number of buttons in the linkedlist                                  */
}ButtonList_t;

/* Function definitions.................................................................................................................*/
void Button_Init(Button_t *a_handle, gpioPin a_pin, GpioState_t a_fnptr, void *a_args);
void Button_ConnectEvent(Button_t *a_handle, ButtonPress_t a_event, EventHandler_t a_eventHandle);
void Button_DisconnectEvent(Button_t *a_handle, ButtonPress_t a_event);
void Button_InitializeList(ButtonList_t *a_list);
void Button_AddToList(ButtonList_t *a_list, Button_t *a_handle);
void Button_PeriodicTask(ButtonList_t *a_list);


#ifdef __cplusplus
}
#endif//__cplusplus

#endif//_BUTTONMODULE_H_