cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME StellarisGfx)
set(CMAKE_CXX_STANDARD 14)

project(${PROJECT_NAME})

set(PLATFORM pc)

include_directories(src/)

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} /usr/lib/libSDL2-2.0.so.0 /usr/lib/libSDL2_image.so)