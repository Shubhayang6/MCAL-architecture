#include "gpio.h"
#include "gpio_config.h"

static const Gpio_ConfigPin gpio_pins[] = {
    {
        .port_base = GPIOA_BASE,
        .pin = 5,
        .direction = GPIO_OUTPUT
    }
};

const Gpio_ConfigType Gpio_Config = {
    .pins = gpio_pins,
    .num_pins = 1
};

int main(void)
{
    Gpio_Init(&Gpio_Config);

    /* LED Blinking loop -- Classic sanity test */
    while(1)
    {
        Gpio_WritePin(5,GPIO_HIGH);
        for(volatile int i = 0; i< 100000;i++);

        Gpio_WritePin(5,GPIO_LOW);
        for(volatile int i = 0; i< 100000;i++);

    }
}



