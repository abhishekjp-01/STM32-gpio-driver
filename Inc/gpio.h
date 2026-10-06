
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

#ifndef __GPIO_H__
#define __GPIO_H__

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


#endif /* __GPIO_H__ */

