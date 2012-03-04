#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "object.h"
#include "item.h"
#include "floor.h"

using namespace std;

class Map {
  public:
    //Map(int x, int y);
    Map();
    ~Map();
    void draw();
    void insertItem(Item *item, int x, int y);
    void insertFloor(Floor *floor, int x, int y);
  private:
    int m_xMapSize;
    int m_yMapSize;
    Object *map[20][20];
};

#endif
