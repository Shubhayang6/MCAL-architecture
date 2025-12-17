cmake_minimum_required(VERSION 3.13)

project(mcal_gpio C ASM)

add_executable(mcal_gpio.elf
    startup/startup.s
    app/main.c
    mcal/gpio/gpio.c
)

target_include_directories(mcal_gpio.elf PRIVATE
    mcal
)

# Compile flags (target-specific)
target_compile_options(mcal_gpio.elf PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -ffreestanding
)

# Link flags (bare metal, NO CRT)
target_link_options(mcal_gpio.elf PRIVATE
    -T ${CMAKE_SOURCE_DIR}/startup/linker.ld
    -nostartfiles
    -nodefaultlibs
)
