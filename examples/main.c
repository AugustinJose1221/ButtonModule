/**
 * @file main.c
 * @author Augustin Jose
 * @brief This is an example program for using the buttonModule functionlities and run various test cases.
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "main.h"

#define TIME_IN_US(time)    (time * 1000000)
#define TIMER_PERIOD        (1.0/1000.0)   // in seconds

struct timeval g_time;
ButtonList_t g_buttonList;

static void timerProcess();
static uint32_t timedifference(struct timeval start, struct timeval end);

static void initButton1(Button_t *button);
static void initButton2(Button_t *button);
static void initButton3(Button_t *button);

/* Callbacks */
static void Button1_SinglePressCallback(void *args);
static void Button1_DoublePressCallback(void *args);
static void Button1_TriplePressCallback(void *args);
static void Button1_LongPressCallback(void *args);
static void Button2_SinglePressCallback(void *args);
static void Button2_DoublePressCallback(void *args);
static void Button2_TriplePressCallback(void *args);
static void Button2_LongPressCallback(void *args);
static void Button3_SinglePressCallback(void *args);
static void Button3_DoublePressCallback(void *args);
static void Button3_TriplePressCallback(void *args);
static void Button3_LongPressCallback(void *args);

int main()
{
    Button_t button1;
    Button_t button2;
    Button_t button3;

    Button_Init(&button1, GPIO_PIN_1, HAL_Read_Pin, NULL);
    Button_Init(&button2, GPIO_PIN_2, HAL_Read_Pin, NULL);
    Button_Init(&button3, GPIO_PIN_3, HAL_Read_Pin, NULL);
    Button_InitializeList(&g_buttonList);

    initButton1(&button1);  
    initButton2(&button2);
    initButton3(&button3);

    while(1)
    {
        timerProcess();
    }

    return 0;
}

static void timerProcess()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    if(timedifference(g_time, now) > TIME_IN_US(TIMER_PERIOD))
    {
        g_time = now;
        Button_PeriodicTask(&g_buttonList);
        runTests();
    }
}

static uint32_t timedifference(struct timeval start, struct timeval end)
{
    return ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec); 
}


static void initButton1(Button_t *button)
{
    Button_ConnectEvent(button, BUTTON_SINGLE_PRESS, Button1_SinglePressCallback);
    Button_ConnectEvent(button, BUTTON_DOUBLE_PRESS, Button1_DoublePressCallback);
    Button_ConnectEvent(button, BUTTON_TRIPLE_PRESS, Button1_TriplePressCallback);
    Button_ConnectEvent(button, BUTTON_LONG_PRESS, Button1_LongPressCallback);

    Button_AddToList(&g_buttonList, button);
}

static void initButton2(Button_t *button)
{
    Button_ConnectEvent(button, BUTTON_SINGLE_PRESS, Button2_SinglePressCallback);
    Button_ConnectEvent(button, BUTTON_DOUBLE_PRESS, Button2_DoublePressCallback);
    Button_ConnectEvent(button, BUTTON_TRIPLE_PRESS, Button2_TriplePressCallback);
    Button_ConnectEvent(button, BUTTON_LONG_PRESS, Button2_LongPressCallback);

    Button_AddToList(&g_buttonList, button);
}

static void initButton3(Button_t *button)
{
    Button_ConnectEvent(button, BUTTON_SINGLE_PRESS, Button3_SinglePressCallback);
    Button_ConnectEvent(button, BUTTON_DOUBLE_PRESS, Button3_DoublePressCallback);
    Button_ConnectEvent(button, BUTTON_TRIPLE_PRESS, Button3_TriplePressCallback);
    Button_ConnectEvent(button, BUTTON_LONG_PRESS, Button3_LongPressCallback);

    Button_AddToList(&g_buttonList, button);
}

/* Callbacks */
static void Button1_SinglePressCallback(void *args)
{
    printf("Button 1 single press\n");
}

static void Button1_DoublePressCallback(void *args)
{
    printf("Button 1 double press\n");
}

static void Button1_TriplePressCallback(void *args)
{
    printf("Button 1 triple press\n");
}

static void Button1_LongPressCallback(void *args)
{
    printf("Button 1 long press\n");
}

static void Button2_SinglePressCallback(void *args)
{
    printf("Button 2 single press\n");
}

static void Button2_DoublePressCallback(void *args)
{
    printf("Button 2 double press\n");
}

static void Button2_TriplePressCallback(void *args)
{
    printf("Button 2 triple press\n");
}

static void Button2_LongPressCallback(void *args)
{
    printf("Button 2 long press\n");
}

static void Button3_SinglePressCallback(void *args)
{
    printf("Button 3 single press\n");
}

static void Button3_DoublePressCallback(void *args)
{
    printf("Button 3 double press\n");
}

static void Button3_TriplePressCallback(void *args)
{
    printf("Button 3 triple press\n");
}

static void Button3_LongPressCallback(void *args)
{
    printf("Button 3 long press\n");
}