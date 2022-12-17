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