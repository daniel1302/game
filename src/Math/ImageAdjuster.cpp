#include "ImageAdjuster.h"
#include <iostream>

ImageAdjuster::ImageAdjuster()
{
}

ImageAdjuster::ImageAdjuster(const sf::Vector2f &screenSize, const sf::Vector2f &imageSize)
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
    std::cout<<"ImageAdjuster::scale()";
}