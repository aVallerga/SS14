#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "maploader.h"

using namespace std;

int main() {
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SS14");

  Map *map = MapLoader::loadMap(&App, "map.png");

  sf::Event Event;
  while(App.IsOpen()) {
    App.PollEvent(Event);

    if(Event.Type == sf::Event::Closed) {
      App.Close();
    } else if(Event.Type == sf::Event::Resized) {
      sf::FloatRect fr(0, 0, Event.Size.Width, Event.Size.Height);
      App.SetView(sf::View(fr));
    }

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    map->draw();
    App.Display();
  }

  return 0;
}
