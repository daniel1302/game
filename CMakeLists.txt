cmake_minimum_required(VERSION 3.8)
project(Arkanoid)

set (Arkanoid_VERSION_MAJOR 0)
set (Arkanoid_VERSION_MINOR 1)

include_directories ("/usr/include")


set (EXTRA_LIBS ${EXTRA_LIBS} sfml-system sfml-window sfml-graphics)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Arkanoid ${SOURCE_FILES})
target_link_libraries (Arkanoid ${EXTRA_LIBS})
