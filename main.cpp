#include "target.hpp"


// Board initialization routine
// The first user-defined this that will be called after reset.
// No static or global object is constructed at this particular moment.
// Usually this routine should perform basic GPIO initialization
extern "C" void board_init()
{
    target_init_gpio();
}

// Simpliest delay
static void dummy_delay()
{
    volatile unsigned int counter = 100000;

    while (counter--) { }
}

// Obviously, main routine
int main(void)
{
    while (1) {
        // Toggle each led one by one

        led_blue::toggle();
        dummy_delay();

        led_green::toggle();
        dummy_delay();

        led_orange::toggle();
        dummy_delay();

        led_red::toggle();
        dummy_delay();
    }

    return 0;
}


