cmake_minimum_required(VERSION 3.4)

# Convenient way to interact with The Core build system.
include(core/build_api.cmake)

# Objvious.
project(blinky_demo)

# Our demo sources.
add_executable(blinky main.cpp)

# Demo depends on theCore.
target_link_libraries(blinky the_core)

# Set of configuration variables.
# Pick the platform.
set(CONFIG_PLATFORM stm32)
# STM32 discovery is running with SMT32F407VG processor.
set(CONFIG_PLATFORM_DEVICE STM32F40_41xxx)
# External oscillator has 8 MHz out clock.
set(CONFIG_PLATFORM_HSE_VAL 8000000)
# Strip executable to binary.
set(CONFIG_EXEC_STRIP true)

# All configuration variables should be defined _before_ call
# to add_subdirectory()

# Add theCore to the build.
add_subdirectory(core)
