cmake_minimum_required(VERSION 3.4)

# Convenient way to interact with The Core build system.
include(core/build_api.cmake)

# Objvious.
project(blinky_demo)

# Our demo sources.
add_executable(blinky main.cpp)

# Demo depends on the core.
target_link_libraries(blinky the_core)

# Set of configuration variables.
# Pick the platform.
set(CONFIG_PLATFORM stm32f4xx)
# STM32 discovery is running with SMT32F407VG processor.
set(CONFIG_PLATFORM_DEVICE STM32F40_41xxx)
# External oscillator has 8 MHz out clock.
set(CONFIG_PLATFORM_HSE_VAL 8000000)
# Strip executable to binary.
set(CONFIG_EXEC_STRIP true)

# All configuration variables should be defined _before_ call
# to register_project()

# Notify The Core about our project.
# register_project() takes two arguments:
# First is the project name, second is the path to object file,
# produced by the project.
register_project(${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/blinky)

# Pay attention that there is no add_subdirectory(core) statement.
# register_project() do this internally so no need to do it explicitly.

