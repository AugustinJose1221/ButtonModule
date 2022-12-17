/**
 * @file userConfig.h
 * @author Augustin Jose
 * @brief This header file contains all the user configurations for 
 * buttonModule functionalities. Setting theuser configurations 
 * overrides the default configurations present in buttonConfig.h 
 * file.
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _USERCONFIG_H_
#define _USERCONFIG_H_

/* Button timer tick period in milliseconds                                         */
#define BUTTON_TIMER_TICK_PERIOD                1u
/* Single press time delay in milliseconds                                          */
#define BUTTON_SINGLE_PRESS_PERIOD              100u
/* Delay between press for multipresses in milliseconds                             */
#define BUTTON_MULTI_PRESS_DELAY                50u
#endif//_USERCONFIG_H_