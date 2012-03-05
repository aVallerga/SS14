#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "map.h"

using namespace std;

int main() {
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SS14");

  // Sprite testing
  sf::Texture floortexture;
  if(!floortexture.LoadFromFile("tiles/floor.png")) {
    cout << "Couldn't find floortile.png" << endl;
    return 0;
  }

  // Actual game setup
  Map *map = new Map(&App);

  sf::Texture walltexture;
  if(!walltexture.LoadFromFile("tiles/wall.png")) {
    cout << "Couldn't find wall.png" << endl;
  }
  Tile *tile = new Tile(&walltexture);
  map->insertTile(tile, 3, 3);
  map->insertTile(tile, 3, 4);
  map->insertTile(tile, 3, 5);
  map->insertTile(tile, 3, 6);
  map->insertTile(tile, 4, 3);
  map->insertTile(tile, 5, 3);
  map->insertTile(tile, 6, 3);
  map->insertTile(tile, 6, 4);
  map->insertTile(tile, 6, 5);
  map->insertTile(tile, 6, 6);
  map->insertTile(tile, 4, 6);
  map->insertTile(tile, 5, 6);

  Tile *floortile = new Tile(&floortexture);
  map->insertTile(floortile, 4, 4);
  map->insertTile(floortile, 4, 5);
  map->insertTile(floortile, 5, 4);
  map->insertTile(floortile, 5, 5);

  map->drawToConsole();

  sf::Event Event;
  while(App.IsOpen()) {
    App.PollEvent(Event);
    if(Event.Type == sf::Event::Closed) {
      App.Close();
    }
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    map->draw();
    App.Display();
  }

  return 0;
}
