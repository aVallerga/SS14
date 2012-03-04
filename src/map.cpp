#include "map.h"

using namespace std;

//Map::Map(int x, int y) {
//  int map[x][y];
//}

Map::Map(sf::RenderWindow *render) {
  m_render = render;
  m_xMapSize = 20;
  m_yMapSize = 20;
  for(int i = 0; i < m_yMapSize; i++)
    for(int j = 0; j < m_xMapSize; j++)
      map[j][i] = 0;
}

Map::~Map() {

}

void Map::drawToConsole() {
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

void Map::draw(sf::Texture &texture) {
  for(int i = 0; i < m_yMapSize; i++) {
    for(int j = 0; j < m_yMapSize; j++) {
      if(map[j][i] != 0) {
        sf::Sprite sprite;
        sprite.SetTexture(texture);
        sprite.SetPosition(j*32, i*32);
        m_render->Draw(sprite);
      }
    }
  }
}

void Map::insertItem(Item *item, int x, int y) {
  map[x][y] = item;
}

void Map::insertFloor(Floor *floor, int x, int y) {
  map[x][y] = floor;
}
