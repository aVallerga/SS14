#include "tile.h"

Tile::Tile(sf::Texture *texture) {
  m_id = 't';
  m_texture = texture;
}

Tile::~Tile() {
}

char Tile::getId() {
  return m_id;
}

sf::Texture* Tile::getTexture() {
  return m_texture;
}
