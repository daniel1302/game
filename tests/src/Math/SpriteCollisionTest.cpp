#include <gtest/gtest.h>
#include "Math/SpriteCollision.h"


/**
   A1
    /-------\           B1.x \in <A1.x; A2.x> && B1.y \in <A1.y; A2.y>
    |       |           A1.x \in <B1.x; B2.x> && A1.y \in <B1.y; B2.y>
    |   A   |
    |   B1/-|----\
    \-----|-/A2  |
          |  B   |
          |      |
          \------/
                  B2
 */


TEST(SpriteCollisionTest, Collision1) {
    ImageAdjuster a;

    sf::Vector2f scale = a.scale();

    ASSERT_FLOAT_EQ(1, scale.x);
    ASSERT_FLOAT_EQ(1, scale.y);
};