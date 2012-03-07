#include "player.h"

using namespace std;

Player::Player(sf::RenderWindow *render) {
  m_render = render;
  m_xPos = 0;
  m_yPos = 0;
  m_texture = Util::getTexture("entity/player.png");
}

Player::~Player() {
}

void Player::moveRight() {
  m_xPos += 32;
}


void Player::moveLeft() {
  m_xPos -= 32;
}

void Player::moveUp() {
  m_yPos -= 32;
}

void Player::moveDown() {
  m_yPos += 32;
}

void Player::draw() {
  sf::Sprite sprite;
  sprite.SetTexture(*m_texture);
  sprite.SetPosition(m_xPos, m_yPos);
  m_render->Draw(sprite);
}
