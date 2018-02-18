#include <cstdlib>
#include <stdint.h>
#include <SFML/Graphics.hpp>

void render(sf::RenderTarget *window);

class TextureItem
{
private:
    uint32_t left;
    uint32_t top;
    uint32_t width;
    uint32_t height;

public:
    TextureItem(
            uint32_t left,
            uint32_t top,
            uint32_t width,
            uint32_t height
    );

    uint32_t getLeft();
    uint32_t getTop();
    uint32_t getWidth();
    uint32_t getHeight();
};

TextureItem::TextureItem(
        uint32_t left,
        uint32_t top,
        uint32_t width,
        uint32_t height
)
: left(left)
, top(top)
, width(width)
, height(height)
{
}

uint32_t TextureItem::getLeft()
{
    return this->left;
}

uint32_t TextureItem::getTop()
{
    return this->top;
}

uint32_t TextureItem::getWidth()
{
    return this->width;
}

uint32_t TextureItem::getHeight()
{
    return this->height;
}


class GameObject
{
public:
    TextureItem *texture;

    struct {
        uint32_t x;
        uint32_t y;
    } position;


public:
    GameObject(TextureItem *texture, uint32_t x, uint32_t y);
};

GameObject::GameObject(TextureItem *texture, uint32_t x, uint32_t y)
{
    this->texture = texture;
    this->position.x = x;
    this-> position.y = y;
}

int main()
{
    TextureItem orangeBlock(0, 0, 64, 32);



    sf::RenderWindow window(sf::VideoMode(1024, 768), "Arkanoid");


    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        render(dynamic_cast<sf::RenderTarget *>(&window));

        window.display();
    }

    return 0;
}

void render(sf::RenderTarget *window)
{
    sf::Texture texture;

    if (texture.loadFromFile("../assets/texture.png") == false) {
        //TODO: Handle ERROR
        std::exit(1);
    }


    sf::IntRect subRect;
    subRect.left = 50;
    subRect.top = 55;
    subRect.width = 80;
    subRect.height = 90;

    sf::Sprite sprite(texture, subRect);

    sprite.setPosition(12, 1);
    window->draw(sprite);
}