cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME StellarisGfx)
set(CMAKE_CXX_STANDARD 14)

project(${PROJECT_NAME})

set(PLATFORM pc)
add_definitions(-DPLATFORM_PC)

include_directories(src/ config/ app/)

set(SOURCE_FILES main.cpp src/sdl/init/init.h src/sdl/init/init.cpp src/sdl/lang.h config/config_pc.h src/pc/PC.cpp src/pc/PC.h src/interface/Bootstrap.h src/struct/Color.h src/struct/Sprite.h src/interface/Drawer.h src/sdl/SdlDraw.cpp src/sdl/SdlDraw.h app/Demo.cpp app/Demo.h src/interface/App.h app/ball/ball.h src/struct/Typeface.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} /usr/lib/libSDL2-2.0.so.0 /usr/lib/libSDL2_image.so)

set(SOURCE_FILES util/BitstreamToFont.h util/BitstreamToFont.cpp app/text/lgfont.font)
add_executable(BitstreamToFont ${SOURCE_FILES})