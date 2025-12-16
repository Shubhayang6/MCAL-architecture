#include "gpio.h"
#include "gpio_config.h"

/* Register Offsets */
#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14
#define GPIO_IDR_OFFSET 0x10

#define REG32(addr) (*(volatile uint32_t*)(addr))

static const Gpio_ConfigType* Gpio_ConfigPtr = 0;

void Gpio_init(const void* ConfigPtr)
{
    Gpio_ConfigPtr = (const Gpio_ConfigType*)ConfigPtr;

    for (uint32_t i = 0; i< Gpio_ConfigPtr->num_pins; i++){
        const Gpio_ConfigPin* cfg = &Gpio_ConfigPtr->pins[i];

        uint32_t moder = REG32(cfg->port_base + GPIO_MODER_OFFSET);
        moder &= ~(0x3 << (cfg->pin * 2));

        if (cfg->direction == GPIO_OUTPUT) {
            moder |= (0x1 << (cfg->pin * 2));
        }

        REG32(cfg->port_base + GPIO_MODER_OFFSET) = moder;
    }
}

void Gpio_WritePin(Gpio_PinType pin, Gpio_LevelType level)
{
    if (level == GPIO_HIGH)
    {
        REG32(GPIOA_BASE + GPIO_ODR_OFFSET) |= (1 << pin);
    }
    else
    {
        REG32(GPIOA_BASE + GPIO_IDR_OFFSET) &= (1 << pin);
    }
}

Gpio_LevelType Gpio_ReadPin(Gpio_PinType pin)
{
    return (REG32(GPIOA_BASE + GPIO_IDR_OFFSET)& (1<<pin)) ? GPIO_HIGH : GPIO_LOW;
}