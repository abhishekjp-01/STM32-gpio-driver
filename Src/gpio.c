/**
 * @file gpio.c 
 * @brief gpio driver file
 *
 * This source file provides n
 *
 * @author Abhishek JP
 * @date 06-10-2026
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "gpio.h"



void gpio_config_default(GPIO_Config_t *config)
{
    if(config == NULL)
        return;
    config->pin = 0;
    config->mode = GPIO_MODE_INPUT;
    config->pupd = GPIO_NO_PUPD;
    config->type = GPIO_OUTPUT_PP;
    config->speed = GPIO_SPEED_LOW;
}


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
 
    if(gpio == GPIOA){
        RCC_AHB1ENR |= (1U << 0);
        (void)RCC_AHB1ENR;
    }
    else if(gpio == GPIOB){
        RCC_AHB1ENR |= (1U << 1);
        (void)RCC_AHB1ENR;
    }
    else if(gpio == GPIOC){
        RCC_AHB1ENR |= (1U << 2);
        (void)RCC_AHB1ENR;
    }
    else if(gpio == GPIOD){
        RCC_AHB1ENR |= (1U << 3);
        (void)RCC_AHB1ENR;
    }
    else if(gpio == GPIOE){
        RCC_AHB1ENR |= (1U << 4);
        (void)RCC_AHB1ENR;
    }
    else if(gpio == GPIOH){
        RCC_AHB1ENR |= (1U << 7);
        (void)RCC_AHB1ENR;
    }
}


void gpio_init( GPIO_RegDef_t* gpio, GPIO_Config_t *config ){
    
  if(gpio == NULL || config == NULL)
    return;

    if(config->pin > MAX_PIN)
    return;

    uint32_t position;
    position = (uint32_t)config->pin*2;

    //gpio Peripheral Clock Enable
    gpio_clock_enable(gpio);

    //gpio Direction configure
    gpio->MODER &= ~(3U << position); //Clear bit field
    gpio->MODER |= ((uint32_t)config->mode << position);
    

    //Pull-up Pull-down Config
    gpio->PUPDR &= ~(3U << position); //Clear bit field
    gpio->PUPDR |= ((uint32_t)config->pupd << position); // Pull-UP or Pull-Down 
   
    //gpio Output Type Configure
    if(config->type == GPIO_OUTPUT_PP ){
        gpio->OTYPER &= ~(1U << config->pin); //Push-Pull
    }
    else()
        gpio->OTYPER |= (1U << config->pin); //Open - Drain


    //Speed Configure
    gpio->OSPEEDR &= ~(3U << position); //Clear bit field
    gpio->OSPEEDR |= ((uint32_t)config->speed << position); //Set-Speed
   

}


void gpio_write(GPIO_RegDef_t *gpio, uint8_t pin, GPIO_State_t state){
    
    if(gpio == NULL || pin > MAX_PIN)
        return;

    if(state == HIGH)
        gpio->BSRR = (1U << pin); //Set pin

    else()
        gpio->BSRR = (1U << (pin + 16)); //Reset bit
    
}
