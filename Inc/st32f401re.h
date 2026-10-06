
/**
 * @file stm32f401re.h
 * @brief This is an MCU Specific header file for stm32f401re
 *
 *
 * @author Abhishek JP
 * @date 06-10-2026
 *
 */
#ifndef STM32F401RE_H
#define STM32F401RE_H

#include <stdint.h>

/* GPIO Register Definition */
 typedef struct{

    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];

}GPIO_RegDef_t;

/* Base Addresses */
#define RCC_BASE 0x40023800U
#define GPIO_BASE 0x40020000U

/* GPIO Peripheral Definitions */
#define GPIOA ((GPIO_RegDef_t*)(GPIO_BASE + 0x00U))
#define GPIOB ((GPIO_RegDef_t*)(GPIO_BASE + 0x0400U))
#define GPIOC ((GPIO_RegDef_t*)(GPIO_BASE + 0x0800U))
#define GPIOD ((GPIO_RegDef_t*)(GPIO_BASE + 0x0C00U))
#define GPIOE ((GPIO_RegDef_t*)(GPIO_BASE + 0x1000U))
#define GPIOH ((GPIO_RegDef_t*)(GPIO_BASE + 0x1C00U))

/* RCC Registers */
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30U))

/* GPIO Limits */
#define MAX_PIN 15U


typedef enum{
    GPIO_NO_PUPD = 0x00U,
    GPIO_PULL_UP = 0x01U,
    GPIO_PULL_DOWN = 0x02U
}GPIO_PuPd_t;

typedef enum{
    
    GPIO_SPEED_LOW       = 0x00U,
    GPIO_SPEED_MEDIUM    = 0x01U,
    GPIO_SPEED_HIGH      = 0x02U,
    GPIO_SPEED_VERY_HIGH = 0x03U
}GPIO_Speed_t;


typedef enum{
    GPIO_OUTPUT_PP = 0,
    GPIO_OUTPUT_OD = 1U
}GPIO_PPOD_t;

typedef enum
{
    GPIO_MODE_INPUT  = 0x00U,
    GPIO_MODE_OUTPUT = 0x01U,
    GPIO_MODE_AF      = 0x02U,
    GPIO_MODE_ANALOG = 0x03U

} GPIO_Mode_t;

typedef struct{

    uint8_t pin;
    GPIO_PuPd_t pupd;
    GPIO_PPOD_t type;
    GPIO_Speed_t speed;
    GPIO_Mode_t mode;

}GPIO_Config_t;

#endif /* STM32F401RE_H */