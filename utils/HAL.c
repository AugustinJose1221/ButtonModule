/**
 * @file HAL.c
 * @author Augustin Jose
 * @brief This file contains all the function for mocking
 * hardware abstraction layer functions for GPIO control.
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "HAL.h"

bool g_gpioPinState[GPIO_PIN_COUNT];

bool HAL_Read_Pin(uint32_t pin)
{
    return g_gpioPinState[pin];
}

void HAL_Set_Pin(uint32_t pin)
{
    g_gpioPinState[pin] = true;
}

void HAL_Reset_Pin(uint32_t pin)
{
    g_gpioPinState[pin] = false;
}