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
 
    if(gpio == GPIOA)
        RCC_AHB1ENR |= (1U << 0);

    else if(gpio == GPIOB)
        RCC_AHB1ENR |= (1U << 1);

    else if(gpio == GPIOC)
        RCC_AHB1ENR |= (1U << 2);

    else if(gpio == GPIOD)
        RCC_AHB1ENR |= (1U << 3);

    else if(gpio == GPIOE)
        RCC_AHB1ENR |= (1U << 4);

    else if(gpio == GPIOH)
        RCC_AHB1ENR |= (1U << 7);
    
}


void gpio_init( GPIO_RegDef_t* gpio, GPIO_Config_t *config ){
    
  if(gpio == NULL || config == NULL)
    return;

    if(config->pin > MAX_PIN)
    return;

    if(gpio == NULL)
    return;
    uint8_t position;
    position = config->pin*2;

    //gpio Peripheral Clock Enable
    gpio_clock_enable(gpio);

    //gpio Direction configure
    if(config->GPIO_MODE == GPIO_MODE_OUTPUT) {

        gpio->MODER &= ~(3U<<position); //Clear bit field
        gpio->MODER |= (1U<<position);

    }
    

    //Type Config
    gpio->PUPDR &= ~(3<<position); //Clear bit field
    gpio->PUPDR |= (config->pupd<<position); // Pull-UP or Pull-Down 
   
    //gpio Output Type Configure
    if(config->type == GPIO_OUTPUT_PP ){
        gpio->OTYPER &= ~(1U << config->pin); //Push-Pull
    }
    else if(config->type == GPIO_OUTPUT_OD){
    
        gpio->OTYPER |= (1U << config->pin); //Open - Drain

    }

    //Speed Configure
    gpio->OSPEEDR &= ~(3U<<position); //Clear bit field
    gpio->OSPEEDR |= (config->speed<<position); //Set-Speed
   

}


