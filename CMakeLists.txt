cmake_minimum_required(VERSION 3.8)
project(Arkanoid)

set (Arkanoid_VERSION_MAJOR 0)
set (Arkanoid_VERSION_MINOR 1)


include_directories (${INCLUDE_DIRECTORIES}
        "/usr/include"
        "./src"
)

set (EXTRA_LIBS ${EXTRA_LIBS}
        sfml-system
        sfml-window
        sfml-graphics
)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES
        src/State.h
        src/definitions.h
        src/StateMachine.h src/StateMachine.cpp
        src/AssetManager.h src/AssetManager.cpp
        src/InputManager.h src/InputManager.cpp
        src/Game.h src/Game.cpp
        src/States/SplashState.cpp src/States/SplashState.h
        src/Math/ImageAdjuster.cpp src/Math/ImageAdjuster.h
        src/States/MainMenuState.cpp src/States/MainMenuState.h
        src/GameObjects/GameText.cpp src/GameObjects/GameText.h
        src/States/GameState.cpp src/States/GameState.h
        src/GameObjects/Block.cpp src/GameObjects/Block.h
        src/Math/SpriteCollision.cpp src/Math/SpriteCollision.h
        src/GameObjects/GameObject.h
        src/GameObjects/Ball.cpp src/GameObjects/Ball.h
        src/GameObjects/Board.cpp src/GameObjects/Board.h
        src/GameObjects/Paddle.cpp src/GameObjects/Paddle.h
        src/EventHandler.cpp src/EventHandler.h
        src/Drawable.h
        src/Helpers/FpsMeterHelper.cpp src/Helpers/FpsMeterHelper.h src/Helpers/PointCounterHelper.cpp src/Helpers/PointCounterHelper.h)

add_library(compiled_sources ${SOURCE_FILES})

add_executable(Arkanoid src/main.cpp)
target_link_libraries(Arkanoid ${EXTRA_LIBS} compiled_sources)



find_package(GTest)
if (GTEST_FOUND)
    enable_testing()
    add_subdirectory(tests)
endif()