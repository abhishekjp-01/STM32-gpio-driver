/**
 * @file gpio.c 
 * @brief gpio driver file
 *
 * <Add Extended Description Here>
 *
 * @author Abhishek JP
 * @date 06-10-2026
 *
 */

#include <stdint.h>
#include "gpio.h"



/**
 * @brief Enables the clock for the specified GPIO peripheral.
 *
 * This function enables the AHB1 clock corresponding to the
 * specified GPIO peripheral.
 *
 * This is an internal helper function and is only accessible
 * within this source file.
 *
 * @param gpio Pointer to the GPIO peripheral whose clock should be enabled.
 *
 * @return void
 */
static void gpio_clock_enable(GPIO_RegDef_t *gpio)
{

}


void gpio_init( GPIO_RegDef_t* gpio, GPIO_Config_t *config ){
    
  

}


