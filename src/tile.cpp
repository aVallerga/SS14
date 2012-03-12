#include "tile.h"

Tile::Tile(sf::Texture *texture, bool open) {
  m_id = 't';
  m_open = open;
  m_texture = texture;
}

Tile::~Tile() {
}

char Tile::getId() {
  return m_id;
}

bool Tile::isOpen() {
  return m_open;
}

sf::Texture* Tile::getTexture() {
  return m_texture;
}
