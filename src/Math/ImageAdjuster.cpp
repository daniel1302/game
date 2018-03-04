#include "ImageAdjuster.h"

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
    _screenSize = vector;
}

void ImageAdjuster::setImageSize(const sf::Vector2f &vector)
{
    _imageSize = vector;
}

sf::Vector2f ImageAdjuster::scale(bool scaleUp)
{
    if (scaleUp == false
        && _screenSize.x >= _imageSize.x
        && _screenSize.y >= _imageSize.y
    )
    {
        return sf::Vector2f(1, 1);
    }

    auto scale = sf::Vector2f(1, 1);

    if (_imageSize.x > _screenSize.x
            || _imageSize.y > _screenSize.y
    )
    {
        if (_imageSize.x > _screenSize.x) {
            scale.x =
            scale.y = _screenSize.x / _imageSize.x;

            _imageSize.x *= scale.x;
            _imageSize.y *= scale.y;
        }

        if (_imageSize.y > _screenSize.y) {
            float multiplier = (_screenSize.y / _imageSize.y);
            scale.y *= multiplier;
            scale.x *= multiplier;

            _imageSize.x *= scale.x;
            _imageSize.y *= scale.y;
        }
    } else {
        float xScale = _screenSize.x / _imageSize.x;
        float yScale =  _screenSize.y / _imageSize.y;

        scale.x = scale.y =(xScale < yScale)
                 ? xScale
                 : yScale;
    }

    return scale;
}