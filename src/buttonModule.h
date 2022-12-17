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

/* Enumerations */
typedef enum{
    BUTTON_NO_PRESS = 0,
    BUTTON_SINGLE_PRESS,
    BUTTON_DOUBLE_PRESS,
    BUTTON_TRIPLE_PRESS,
    BUTTON_LONG_PRESS,
    BUTTON_PRESS_COUNT,
}ButtonPress_t;

typedef enum{
    BUTTON_NOT_PRESSED = false,
    BUTTON_PRESSED = true,
}ButtonState_t;

typedef enum{
    BUTTON_IDLE = 0,
    BUTTON_FIRST_PRESS,
    BUTTON_FIRST_RELEASE,
    BUTTON_SECOND_PRESS,
    BUTTON_SECOND_RELEASE,
    BUTTON_THIRD_PRESS,
    BUTTON_THIRD_RELEASE,
    BUTTON_LONG_RELEASE,
}ButtonTrigger_t;

/* Function pointer definitions */
typedef bool (*GpioState_t)(gpioPin);
typedef void (*EventHandler_t)(void*);

/* Structure definitions */
typedef struct Button_t{
    gpioPin pin;
    ButtonState_t pinState;
    ButtonTrigger_t state;
    uint32_t tickCount;
    GpioState_t getGpioPinState;
    EventHandler_t callbackList[BUTTON_PRESS_COUNT];
    struct Button_t *nextInList;
    void *argptr;
}Button_t;

typedef struct{
    Button_t *start;
    Button_t *end;
    uint32_t buttonCount;
}ButtonList_t;

/* Function definitions */
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