#include "map.h"

using namespace std;

int main() {
  //int xMapSize = 20;
  //int yMapSize = 20;
  //Map *map = new Map(xMapSize, yMapSize);
  Map *map = new Map();

  Item *item = new Item();
  int x = 5;
  int y = 5;
  map->insertItem(item, x, y);
  x = 6;
  Floor *floor = new Floor();
  map->insertFloor(floor, x, y);
  
  map->draw();

  return 0;
}
