#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "object.h"
#include "item.h"
#include "floor.h"

using namespace std;

class Map {
  public:
    //Map(int x, int y);
    Map(sf::RenderWindow *render);
    ~Map();
    void drawToConsole();
    void draw(sf::Texture &texture);
    void insertItem(Item *item, int x, int y);
    void insertFloor(Floor *floor, int x, int y);
  private:
    int m_xMapSize;
    int m_yMapSize;
    sf::RenderWindow *m_render;
    Object *map[20][20];
};

#endif
