/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
//! \file
//! \brief Blinky theCore demo.
//! \details Example shows how to use LEDs within theCore.

// Generated definitions from theCore.
// This will introduce led_blue, led_green, led_orange and led_red.
#include <aux/generated.hpp>

// For wait_for() routine
#include <common/execution.hpp>

//! Board initialization routine.
//! \details The first user-defined this that will be called after reset.
//! No static or global object is constructed at this particular moment.
//! Usually this routine should perform basic GPIO initialization.
extern "C" void board_init()
{
    gpio_init_generated();
}

//! Main routine.
int main(void)
{
    while (1) {
        // Toggle each led one by one

        ecl::led_blue::toggle();
        ecl::wait_for(500); // Wait 500 ms

        ecl::led_green::toggle();
        ecl::wait_for(500); // Wait 500 ms

        ecl::led_orange::toggle();
        ecl::wait_for(500); // Wait 500 ms

        ecl::led_red::toggle();
        ecl::wait_for(500); // Wait 500 ms
    }

    return 0;
}


