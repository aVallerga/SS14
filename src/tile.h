#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
  public:
    Tile(sf::Texture *texture);
    ~Tile();
    char getId();
    sf::Texture* getTexture();
  private:
    char m_id;
    sf::Texture* m_texture;
};

#endif
