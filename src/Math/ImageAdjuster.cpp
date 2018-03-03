#include "ImageAdjuster.h"


ImageAdjuster::ImageAdjuster()
{
}

ImageAdjuster::ImageAdjuster(const sf::Vector2f &screenSize, const sf::Vector2 &imageSize)
{
    _screenSize = screenSize;
    _imageSize = imageSize;
}

void ImageAdjuster::setScreenSize(const sf::Vector2f &vector)
{
    _imageSize = vector;
}

void ImageAdjuster::setImageSize(const sf::Vector2f &vector)
{
    _imageSize = vector;
}

sf::Vector2f ImageAdjuster::scale(bool scaleUp)
{
//    if ()
}