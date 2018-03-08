project(Arkanoid-Tests)

include_directories (${INCLUDE_DIRECTORIES}
        "./tests/src"
)

set(EXTRA_LIBS ${EXTRA_LIBS} compiled_sources gtest)



set(MATH_TEST_SOURCE_FILES
        ./src/Math/ImageAdjusterTest.cpp)

set(GAME_OBJECT_TEST_SOURCE_FILES
        src/GameObjects/GameTextTest.cpp)


add_executable(testMath ${MATH_TEST_SOURCE_FILES})
target_link_libraries(testMath gtest_main ${EXTRA_LIBS})
add_test(testMath testMath)


add_executable(testGameObjects ${GAME_OBJECT_TEST_SOURCE_FILES})
target_link_libraries(testGameObjects gtest_main ${EXTRA_LIBS})
add_test(testGameObjects testGameObjects)