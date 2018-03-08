#ifndef ARKANOID_MAINMENUSTRING_H
#define ARKANOID_MAINMENUSTRING_H


#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class GameText {
public:
    enum Align
    {
        Center  = 0,
        Left    = 1<<0,
        Right   = 1<<1,
        Fixed   = 1<<2,
        Top     = 1<<3,
        Middle  = 1<<4,
        Bottom  = 1<<5
    };

    GameText(
            const char *text,
            const sf::Font &font,
            const unsigned int fontSize=20,
            const sf::Color &color=sf::Color::White,
            sf::Text::Style style = sf::Text::Style::Regular,
            const unsigned int align = GameText::Fixed,
            sf::Vector2f position = sf::Vector2f(0,0)
    );

    sf::Text &getText();

    unsigned int getAlign();


private:
    const unsigned int _align ;
    sf::Text _text;
    void toCenter();
    void toLeft();
    void toRight();
    void toTop();
    void toMiddle();
    void toBottom();

};

#endif //ARKANOID_MAINMENUSTRING_H
