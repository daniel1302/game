project(Arkanoid-Tests)

include_directories (${INCLUDE_DIRECTORIES}
        "./tests/src"
)

set(TEST_SOURCE_FILES
        ./src/mainTests.cpp
        ./src/Math/ImageAdjusterTest.cpp ../src/Math/ImageAdjuster.h ../src/Math/ImageAdjuster.cpp)

add_executable(tests ${TEST_SOURCE_FILES})

target_link_libraries(tests ${EXTRA_LIBS} gtest)
