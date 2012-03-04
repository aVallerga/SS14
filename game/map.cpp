#include "map.h"

using namespace std;

//Map::Map(int x, int y) {
//  int map[x][y];
//}

Map::Map() {
  m_xMapSize = 20;
  m_yMapSize = 20;
  for(int i = 0; i < m_yMapSize; i++)
    for(int j = 0; j < m_xMapSize; j++)
      map[j][i] = 0;
}

Map::~Map() {

}

void Map::draw() {
  for(int i = 0; i < m_yMapSize; i++) {
    for(int j = 0; j < m_xMapSize; j++) {
      if(map[j][i] == 0)
        cout << "-";
      else
        cout << map[j][i]->getId();
    }
    cout << endl;
  }
}

void Map::insertItem(Item *item, int x, int y) {
  map[x][y] = item;
}

void Map::insertFloor(Floor *floor, int x, int y) {
  map[x][y] = floor;
}
