#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "map.h"

using namespace std;

int main() {
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SS14");

  // Sprite testing
  sf::Texture texture;
  if(!texture.LoadFromFile("floortile.png")) {
    cout << "Couldn't find floortile.png" << endl;
    return 0;
  }

  // Actual game setup
  Map *map = new Map(&App);

  Item *item = new Item();
  int x = 5;
  int y = 5;
  map->insertItem(item, x, y);
  x = 6;
  Floor *floor = new Floor();
  map->insertFloor(floor, x, y);
  x = 7;
  y = 6;
  map->insertFloor(floor, x, y);
  
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
    map->draw(texture);
    App.Display();
  }

  return 0;
}
