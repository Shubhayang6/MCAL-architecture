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
