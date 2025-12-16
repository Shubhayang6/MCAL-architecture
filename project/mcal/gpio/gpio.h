#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

/* Public types */
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} Gpio_LevelType;

typedef uint32_t Gpio_PinType;

/* APIs */
void Gpio_Init(const void* ConfigPtr);
void Gpio_WritePin(Gpio_PinType pin, Gpio_LevelType level);
Gpio_LevelType Gpio_ReadPin(Gpio_PinType pin);

#endif