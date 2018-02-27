#ifndef ARKANOID_ASSETMANAGER_H
#define ARKANOID_ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>


class AssetManager
{
public:
    AssetManager() {}
    ~AssetManager() {}

    void loadTexture(std::string const& name, std::string const& filePath);
    sf::Texture &getTexture(std::string const& name);


    void loadFont(std::string const& name, std::string const& filePath);
    sf::Font &getFont(std::string const& name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;

};

#endif //ARKANOID_ASSETMANAGER_H
