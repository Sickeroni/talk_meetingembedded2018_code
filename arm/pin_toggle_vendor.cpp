// kinetis SDK header
#include <MK64F12.h>

//#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

//#include "clock_config.h"
//#include "pin_mux.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
 // We toggle GPIO C16
#define PIN_TO_TOGGLE_PORT GPIOC
#define PIN_TO_TOGGLE_PIN 16U


// kvasir header
//#include "Chip/MK64F12.hpp"

extern "C" {


int main(void); // needed here to be callable in main.c (otherwise name mangeling mismatch)
}


void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

int main()
{
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);

    /* PORTC16 is configured as GPIO*/
    PORT_SetPinMux(PORTC, PIN_TO_TOGGLE_PIN, kPORT_MuxAsGpio);

    /* Init output LED GPIO. */
    gpio_pin_config_t led_config = {
            kGPIO_DigitalOutput, 0,
    };
    GPIO_PinInit(PIN_TO_TOGGLE_PORT, PIN_TO_TOGGLE_PIN, &led_config);

    while (1)
    {
      //  delay();
        GPIO_PortToggle(PIN_TO_TOGGLE_PORT, 1u << PIN_TO_TOGGLE_PIN);
    }
}
