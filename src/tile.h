#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
  public:
    Tile(sf::Texture *texture, bool open);
    ~Tile();
    char getId();
    bool isOpen();
    sf::Texture* getTexture();
  private:
    char m_id;
    bool m_open;
    sf::Texture* m_texture;
};

#endif
