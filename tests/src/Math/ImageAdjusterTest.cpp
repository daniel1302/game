#include <gtest/gtest.h>
#include "Math/ImageAdjuster.h"

TEST(ImageAdjusterTest, InitState) {
    ImageAdjuster a;

    sf::Vector2f scale = a.scale();

    ASSERT_FLOAT_EQ(1, scale.x);
    ASSERT_FLOAT_EQ(1, scale.y);
};

TEST(ImageAdjusterTest, NoScale) {
    ImageAdjuster a = ImageAdjuster(
            sf::Vector2f(100, 100),
            sf::Vector2f(100, 100)
    );

    sf::Vector2f scale = a.scale();


    ASSERT_FLOAT_EQ(1, scale.x);
    ASSERT_FLOAT_EQ(1, scale.y);

    a.setScreenSize(sf::Vector2f(200, 200));
    a.setImageSize(sf::Vector2f(199, 199));

    scale = a.scale();

    ASSERT_FLOAT_EQ(1, scale.x);
    ASSERT_FLOAT_EQ(1, scale.y);
}

TEST(ImageAdjusterTest, ScaleWhenScreenWidthIsGreaterThanHeight) {
    ImageAdjuster a = ImageAdjuster(
            sf::Vector2f(100, 50),
            sf::Vector2f(200, 100)
    );

    sf::Vector2f scale = a.scale();
    ASSERT_FLOAT_EQ(0.5, scale.x);
    ASSERT_FLOAT_EQ(0.5, scale.y);


    a.setImageSize(sf::Vector2f(100, 100));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.5, scale.x);
    ASSERT_FLOAT_EQ(0.5, scale.y);


    a.setImageSize(sf::Vector2f(50, 200));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.25, scale.x);
    ASSERT_FLOAT_EQ(0.25, scale.y);


    a.setImageSize(sf::Vector2f(500, 10));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.2, scale.x);
    ASSERT_FLOAT_EQ(0.2, scale.y);
}

TEST(ImageAdjusterTest, ScaleWhenScreenHeightIsGreaterThanWidth) {
    ImageAdjuster a = ImageAdjuster(
            sf::Vector2f(50, 100),
            sf::Vector2f(200, 100)
    );

    sf::Vector2f scale = a.scale();
    ASSERT_FLOAT_EQ(0.25, scale.x);
    ASSERT_FLOAT_EQ(0.25, scale.y);


    a.setImageSize(sf::Vector2f(100, 100));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.5, scale.x);
    ASSERT_FLOAT_EQ(0.5, scale.y);


    a.setImageSize(sf::Vector2f(50, 400));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.25, scale.x);
    ASSERT_FLOAT_EQ(0.25, scale.y);


    a.setImageSize(sf::Vector2f(500, 10));
    scale = a.scale();
    ASSERT_FLOAT_EQ(0.1, scale.x);
    ASSERT_FLOAT_EQ(0.1, scale.y);
}


TEST(ImageAdjusterTest, ScaleUp)
{
    ImageAdjuster a = ImageAdjuster(
            sf::Vector2f(200, 100),
            sf::Vector2f(50, 100)
    );

    sf::Vector2f scale = a.scale(true);
    ASSERT_FLOAT_EQ(1, scale.x);
    ASSERT_FLOAT_EQ(1, scale.y);

    a.setImageSize(sf::Vector2f(50, 10));
    scale = a.scale(true);
    ASSERT_FLOAT_EQ(4, scale.x);
    ASSERT_FLOAT_EQ(4, scale.y);

    a.setImageSize(sf::Vector2f(50, 25));
    scale = a.scale(true);
    ASSERT_FLOAT_EQ(4, scale.x);
    ASSERT_FLOAT_EQ(4, scale.y);

    a.setImageSize(sf::Vector2f(50, 40));
    scale = a.scale(true);
    ASSERT_FLOAT_EQ(2.5, scale.x);
    ASSERT_FLOAT_EQ(2.5, scale.y);
}