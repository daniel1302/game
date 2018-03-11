#include "GameText.h"
#include "definitions.h"

GameText::GameText(
        const char *text,
        const sf::Font &font,
        const unsigned int fontSize,
        const sf::Color &color,
        sf::Text::Style style,
        const unsigned int align,
        sf::Vector2f position
)
: _align(align)
{
    _text.setString(std::string(text));
    _text.setFont(font);
    _text.setFillColor(color);
    _text.setCharacterSize(fontSize);
    _text.setStyle(style);

    if (align & Align::Right)
    {
        this->toRight();
    }
    else if (align & Align::Center)
    {
        this->toCenter();
    }
    else if (align & Align::Left)
    {
        this->toLeft();
    }
    else
    {
        _text.setPosition(
                position.x,
                _text.getPosition().y
        );
    }

    if (align & Align::Top)
    {
        this->toTop();
    }
    else if (align & Align::Bottom)
    {
        this->toBottom();
    }
    else if (align & Align::Middle)
    {
        this->toMiddle();
    }
    else
    {
        _text.setPosition(
                _text.getPosition().x,
                position.y
        );
    }

}

sf::Text& GameText::getText()
{
    return _text;
}

unsigned int GameText::getAlign()
{
    return _align;
}

void GameText::toLeft()
{
    _text.setPosition(0, _text.getPosition().y);
}

void GameText::toCenter()
{
    sf::FloatRect textRect = _text.getLocalBounds();

    _text.setOrigin(
            textRect.left + textRect.width/2.0,
            textRect.top + textRect.height/2.0
    );

    _text.setPosition(
            SCREEN_WIDTH/2.0,
            _text.getPosition().y

    );
}

void GameText::toRight()
{
    _text.setPosition(
            SCREEN_WIDTH - _text.getLocalBounds().width,
            _text.getPosition().y);
}

void GameText::toTop()
{
    _text.setPosition(_text.getPosition().x, 0);
}

void GameText::toMiddle()
{
    sf::FloatRect textRect = _text.getLocalBounds();

    _text.setOrigin(
            textRect.left+ textRect.width/2.0,
            textRect.top + textRect.height/2.0
    );

    _text.setPosition(
            _text.getPosition().x,
            SCREEN_HEIGHT/2.0

    );
}

void GameText::toBottom()
{
    _text.setPosition(
            _text.getPosition().x,
            SCREEN_HEIGHT - _text.getLocalBounds().height);
}