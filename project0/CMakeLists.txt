cmake_minimum_required(VERSION 3.10)
project(project0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(project0 main.cpp SDL_Plotter.h color_rgb.h)
target_link_libraries(project0 SDL2main SDL2 SDL2_mixer)