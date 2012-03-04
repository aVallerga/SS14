#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
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

  sf::Window App(sf::VideoMode(800, 600, 32), "SS14");

  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.f, 1.f, 1.f, 500.f);

  sf::Event Event;
  while(App.IsOpen()) {
    App.PollEvent(Event);
    if(Event.Type == sf::Event::Closed) {
      App.Close();
    }
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    App.Display();
  }

  return 0;
}
