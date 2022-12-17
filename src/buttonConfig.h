/**
 * @file buttonConfig.h
 * @author Augustin Jose
 * @brief This file contains all the default configurations for buttonModule functions.
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _BUTTON_CONFIG_H_
#define _BUTTON_CONFIG_H_

#include "userConfig.h"

/* Mandatory configurations */

/* Button timer tick period in milliseconds */
#ifndef BUTTON_TIMER_TICK_PERIOD
#define BUTTON_TIMER_TICK_PERIOD                0u
#endif//BUTTON_TIMER_TICK_PERIOD  

/* Single press time delay in milliseconds */
#ifndef BUTTON_SINGLE_PRESS_PERIOD
#define BUTTON_SINGLE_PRESS_PERIOD              0u
#endif//BUTTON_SINGLE_PRESS_PERIOD

/* Delay between press for multipresses in milliseconds */
#ifndef BUTTON_MULTI_PRESS_DELAY            
#define BUTTON_MULTI_PRESS_DELAY                0u
#endif//BUTTON_MULTI_PRESS_DELAY



#endif//_BUTTON_CONFIG_H_