#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "map.h"

using namespace std;

class MapLoader {
  public:
    static Map* loadMap(sf::RenderWindow *render, string filename);
  private:
    static sf::Image* loadMapFromFile(string filename);
    static sf::Texture* getTexture(string filename);
    MapLoader();
};

#endif
