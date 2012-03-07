#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "maploader.h"

using namespace std;

class Player {
  public:
    Player(sf::RenderWindow *render);
    ~Player();
    int getXPos();
    int getYPos();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void draw();
  private:
    int m_xPos;
    int m_yPos;
    sf::Texture* m_texture;
    sf::RenderWindow *m_render;
};

#endif
