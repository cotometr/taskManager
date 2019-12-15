cmake_minimum_required(VERSION 3.6)
project(task)

set(CMAKE_CXX_STANDARD 11)

include_directories(/opt/arduino-1.8.2/libraries/SoftwareSerial)
include_directories(/opt/arduino-1.8.2/hardware/arduino/avr/cores/arduino)
include_directories(/opt/arduino-1.8.2/hardware/arduino/variants/micro)
include_directories(../log)

set(SOURCE_FILES test/main.cpp task.cpp task.h task_manager.cpp task_manager.h)
#set(SOURCE_FILES test/main.cpp)

add_executable(task ${SOURCE_FILES})