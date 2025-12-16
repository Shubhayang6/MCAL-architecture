cmake cmake_minimum_required(VERSION 3.13)

project (mcal_gpio C ASM)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)

set(CMAKE_C_FLAGS "-mpcu=cortex-m4 -mthumb =O0 -g")

add_executable(
    mcal_gpio.elf
    startup/startup.s
    app/main.c
    mcal/gpio/gpio.c
)

target_include_directories(mcal_gpio.elf PRIVATE mcal/gpio)

set_target_properties(mcal_gpio.elf PROPERTIES
    LINK_FLAGS "-T startup/linked.ld -nostartfiles"
)