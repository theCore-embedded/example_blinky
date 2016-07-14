// This file contains target-level abstractions.
// To be concrete it abstracts stm32f4xx Discovery's LEDs

// According to schamatics of stm32f4 Disocvery has 4 LEDs:
// Orange   - PD13
// Green    - PD12
// Red      - PD14
// Blue     - PD15

// See stm32 disovery reference manual for deatils:
// http://www.st.com/st-web-ui/static/active/cn/resource/technical/document/user_manual/DM00039084.pdf
// You may also want to check stm32f4 MCU itself, here is reference manual:
// http://www.st.com/web/en/resource/technical/document/reference_manual/DM00031020.pdf

#ifndef BLINKY_DEMO_TARGET_HPP_
#define BLINKY_DEMO_TARGET_HPP_

#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>

#include <platform/gpio_device.hpp>

// Initialize LED GPIOs
// For simplicity, this implemented as standalone
// global routine.

static void target_init_gpio()
{
    // Initialization structure
    GPIO_InitTypeDef init_struct;

    // Put structure at required state
    GPIO_StructInit(&init_struct);

    // LED GPIO configuration

    init_struct.GPIO_Mode   = GPIO_Mode_OUT;
    init_struct.GPIO_OType  = GPIO_OType_PP;
    init_struct.GPIO_PuPd   = GPIO_PuPd_NOPULL;
    init_struct.GPIO_Pin    = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

    // Init Port D clocks
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    // Init Port D itself
    GPIO_Init(GPIOD, &init_struct);

    // All GPIOs are configured. We are ready to use it.
}

// Define LED types

using led_red 		= ecl::gpio< ecl::gpio_port::d, ecl::gpio_num::pin14 >;
using led_green 	= ecl::gpio< ecl::gpio_port::d, ecl::gpio_num::pin12 >;
using led_blue  	= ecl::gpio< ecl::gpio_port::d, ecl::gpio_num::pin15 >;
using led_orange 	= ecl::gpio< ecl::gpio_port::d, ecl::gpio_num::pin13 >;


#endif
