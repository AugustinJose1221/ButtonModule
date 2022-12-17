#ifndef _HAL_H_
#define _HAL_H_

#include <stdbool.h>
#include <stdint.h>

/* Enumerations */
typedef enum{
    GPIO_PIN_1 = 0,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_COUNT,
}GPIOPin_t;

bool HAL_Read_Pin(uint32_t pin);
void HAL_Set_Pin(uint32_t pin);
void HAL_Reset_Pin(uint32_t pin);

#endif//_HAL_H_