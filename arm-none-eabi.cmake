# We are cross-compiling
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Compiler paths
set(ARM_GCC_PATH "C:/Program Files (x86)/Arm GNU Toolchain arm-none-eabi/14.3 rel1/bin")

set(CMAKE_C_COMPILER   ${ARM_GCC_PATH}/arm-none-eabi-gcc.exe)
set(CMAKE_ASM_COMPILER ${ARM_GCC_PATH}/arm-none-eabi-gcc.exe)

# Architecture flags ONLY
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -ffreestanding")
set(CMAKE_ASM_FLAGS "-mcpu=cortex-m4 -mthumb")

# Prevent try-run
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
