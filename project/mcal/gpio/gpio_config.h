#include <stdint.h>
typedef enum{
    GPIO_INPUT,
    GPIO_OUTPUT
} Gpio_DirectionType;

typedef struct{
    uint32_t port_base;
    uint8_t pin;
    Gpio_DirectionType direction;
} Gpio_ConfigPin;

typedef struct 
{
    const Gpio_ConfigPin* pins;
    uint32_t num_pins;
} Gpio_ConfigType;

#define GPIO_MODER_OFFSET 0x00
#define GPIO_ODR_OFFSET 0x14
#define GPIO_IDR_OFFSET 0x10
