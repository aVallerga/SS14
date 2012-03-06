#include "maploader.h"

Map* MapLoader::loadMap(sf::RenderWindow *render, string filename) {
  Map *map = new Map(render);
  sf::Image* mapimage = loadMapFromFile(filename);
  for(int i = 0; i < mapimage->GetWidth(); i++) {
    for(int j = 0; j < mapimage->GetHeight(); j++) {
      sf::Color pixel = mapimage->GetPixel(j, i);
      Tile *tile = NULL;
      if(pixel.r == 153 && pixel.g == 153 && pixel.b == 153) {
        tile = new Tile(Util::getTexture("tiles/floor.png"));
      } else if(pixel.r == 0 && pixel.g == 0 && pixel.b == 0) {
        tile = new Tile(Util::getTexture("tiles/wall.png"));
      }
      if(tile != NULL) {
        map->insertTile(tile, j, i);
      }
    }
  }
  return map;
}

sf::Image* MapLoader::loadMapFromFile(string filename) {
  sf::Image *mapimage = new sf::Image;
  if(!mapimage->LoadFromFile(filename)) {
    cerr << "Error: Map file not found" << endl;
    exit(1);
  }
  return mapimage;
}
