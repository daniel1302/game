#include <gtest/gtest.h>
#include <GameObjects/GameText.h>
#include "Math/ImageAdjuster.h"
#include "definitions.h"

TEST(GameText, InitState) {
    sf::Font someFont;
    GameText text("GameOver", someFont);

    ASSERT_STREQ("GameOver", text.getText().getString().toAnsiString().c_str());
    ASSERT_FLOAT_EQ(0, text.getText().getPosition().x);
    ASSERT_FLOAT_EQ(0, text.getText().getPosition().y);
    ASSERT_EQ(20, text.getText().getCharacterSize());
    ASSERT_EQ(GameText::Align::Fixed, text.getAlign());
};

TEST(GameText, CustomFixedPosition)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver2",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Fixed,
            sf::Vector2f(12, 14)
    );


    ASSERT_STREQ("GameOver2", text.getText().getString().toAnsiString().c_str());
    ASSERT_FLOAT_EQ(12, text.getText().getPosition().x);
    ASSERT_FLOAT_EQ(14, text.getText().getPosition().y);
    ASSERT_EQ(55, text.getText().getCharacterSize());
    ASSERT_EQ(GameText::Align::Fixed, text.getAlign());
}

TEST(GameText, AlignLeft)
{

    sf::Font someFont;
    GameText text = GameText(
            "GameOver2",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Left,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(0, text.getText().getPosition().x);
    ASSERT_FLOAT_EQ(14, text.getText().getPosition().y);
    ASSERT_EQ(GameText::Align::Left, text.getAlign());
}

TEST(GameText, AlignTopLeft)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver2",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Left | GameText::Align::Top,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(0, text.getText().getPosition().x);
    ASSERT_FLOAT_EQ(0, text.getText().getPosition().y);
    ASSERT_EQ(GameText::Align::Left | GameText::Align::Top, text.getAlign());
}

TEST(GameText, AlignTopRight)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver2",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Right | GameText::Align::Top,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(
            SCREEN_WIDTH - text.getText().getLocalBounds().width,
            text.getText().getPosition().x
    );

    ASSERT_FLOAT_EQ(0, text.getText().getPosition().y);
    ASSERT_EQ(GameText::Align::Right | GameText::Align::Top, text.getAlign());
}

TEST(GameText, AlignTopCenter)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Center | GameText::Align::Top,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(
            SCREEN_WIDTH/2.0,
            text.getText().getPosition().x
    );

    ASSERT_FLOAT_EQ(0, text.getText().getPosition().y);
    ASSERT_EQ(GameText::Align::Center | GameText::Align::Top, text.getAlign());
}

TEST(GameText, AlignMiddleCenter)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Center | GameText::Align::Middle,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(
            SCREEN_WIDTH/2.0,
            text.getText().getPosition().x
    );

    ASSERT_FLOAT_EQ(
            SCREEN_HEIGHT/2.0,
            text.getText().getPosition().y
    );

    ASSERT_EQ(GameText::Align::Center | GameText::Align::Middle, text.getAlign());
}


TEST(GameText, AlignCenterFixed)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Center | GameText::Align::Fixed,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(
            SCREEN_WIDTH/2.0,
            text.getText().getPosition().x
    );

    ASSERT_FLOAT_EQ(
            14,
            text.getText().getPosition().y
    );

    ASSERT_EQ(GameText::Align::Center | GameText::Align::Fixed, text.getAlign());
}

TEST(GameText, AlignCenterMiddleFixed)
{
    sf::Font someFont;
    GameText text = GameText(
            "GameOver",
            someFont,
            55,
            sf::Color::White,
            sf::Text::Style::Bold,
            GameText::Align::Center | GameText::Align::Middle | GameText::Align::Fixed,
            sf::Vector2f(12, 14)
    );

    ASSERT_FLOAT_EQ(
            SCREEN_WIDTH/2.0,
            text.getText().getPosition().x
    );

    ASSERT_FLOAT_EQ(
            SCREEN_HEIGHT/2.0,
            text.getText().getPosition().y
    );


    ASSERT_EQ(GameText::Align::Center | GameText::Align::Middle | GameText::Align::Fixed, text.getAlign());
}
