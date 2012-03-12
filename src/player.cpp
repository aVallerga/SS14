#include "player.h"

using namespace std;

Player::Player(sf::RenderWindow *render, Map *map) {
  m_render = render;
  m_map = map;
  m_xPos = 1;
  m_yPos = 1;
  m_texture = Util::getTexture("entity/player.png");
}

Player::~Player() {
}

void Player::moveRight() {
  if(m_map->isTileOpen(m_xPos+1, m_yPos))
    m_xPos += 1;
}


void Player::moveLeft() {
  if(m_map->isTileOpen(m_xPos-1, m_yPos))
    m_xPos -= 1;
}

void Player::moveUp() {
  if(m_map->isTileOpen(m_xPos, m_yPos-1))
    m_yPos -= 1;
}

void Player::moveDown() {
  if(m_map->isTileOpen(m_xPos, m_yPos+1))
    m_yPos += 1;
}

void Player::draw() {
  sf::Sprite sprite;
  sprite.SetTexture(*m_texture);
  sprite.SetPosition(m_xPos*32, m_yPos*32);
  m_render->Draw(sprite);
}
