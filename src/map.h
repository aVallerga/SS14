#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "tile.h"

using namespace std;

class Map {
  public:
    //Map(int x, int y);
    Map(sf::RenderWindow *render);
    ~Map();
    void drawToConsole();
    void draw();
    void insertTile(Tile *tile, int x, int y);
  private:
    int m_xMapSize;
    int m_yMapSize;
    sf::RenderWindow *m_render;
    Tile *map[20][20];
};

#endif
