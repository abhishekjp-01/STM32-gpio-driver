
/**
 * @file gpio.h
 * @brief GPIO driver interface
 *
 * This header file provides the public interface for configuring
 * and initializing GPIO peripherals.
 *
 * @author Abhishek JP
 * @date 06-10-2026
 *
 */

#ifndef GPIO_H
#define GPIO_H

#include "stm32f401re.h"


/**
 * @brief Initializes a GPIO configuration structure with default values.
 *
 * This function initializes the configuration structure with default
 * GPIO settings. Individual configuration parameters can be modified
 * by the caller after calling this function.
 *
 * @param config Pointer to the GPIO configuration structure.
 *
 * @return void
 */
void gpio_config_default(GPIO_Config_t *config);


/**
 * @brief Initializes a GPIO peripheral according to the specified configuration.
 *
 * This function enables the GPIO peripheral clock and configures the
 * selected GPIO pin according to the parameters provided in the
 * GPIO configuration structure.
 *
 * @param gpio Pointer to the GPIO peripheral to be configured.
 * @param config Pointer to the GPIO configuration structure.
 *
 * @return void
 */
void gpio_init(GPIO_RegDef_t *gpio, GPIO_Config_t *config);


/**
 * @brief Sets or resets the specified GPIO pin.
 *
 * This function writes a HIGH or LOW state to the specified GPIO pin
 * using the GPIO Bit Set/Reset Register (BSRR).
 *
 * @param gpio Pointer to the GPIO peripheral to be controlled.
 * @param pin  Pin number (0 to MAX_PIN).
 * @param state Desired GPIO state (HIGH or LOW).
 *
 * @return void
 */
void gpio_write(GPIO_RegDef_t *gpio, uint8_t pin, GPIO_State_t state);


#endif /* GPIO_H */

