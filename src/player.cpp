#include "player.h"

using namespace std;

Player::Player(sf::RenderWindow *render) {
  m_render = render;
  m_xPos = 0;
  m_yPos = 0;
}

Player::~Player() {
}

void Player::moveRight() {
  m_xPos += 1;
}


void Player::moveLeft() {
  m_xPos -= 1;
}

void Player::moveUp() {
  m_yPos += 1;
}

void Player::moveDown() {
  m_yPos -= 1;
}

void Player::draw() {
  sf::Sprite sprite;
  sprite.SetTexture(*Util::getTexture("entity/player.png"));
  sprite.SetPosition(m_xPos, m_yPos);
  m_render->Draw(sprite);
}
