#ifndef ARKANOID_IMAGEADJUSTER_H
#define ARKANOID_IMAGEADJUSTER_H


#include <SFML/System.hpp>

class ImageAdjuster
{
public:
    ImageAdjuster();
    ImageAdjuster(const sf::Vector2f &screenSize, const sf::Vector2f &imageSize);

    sf::Vector2f scale(bool scaleUp=false);

    void setScreenSize(const sf::Vector2f &vector);
    void setImageSize(const sf::Vector2f &vector);

private:
    sf::Vector2f _screenSize = sf::Vector2f(1, 1);
    sf::Vector2f _imageSize = sf::Vector2f(1, 1);
};


#endif //ARKANOID_IMAGEADJUSTER_H
