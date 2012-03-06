#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "maploader.h"
#include "player.h"

using namespace std;

int main() {
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SS14");

  Map *map = MapLoader::loadMap(&App, "map.png");

  Player *player = new Player(&App);

  sf::Event Event;
  while(App.IsOpen()) {
    App.PollEvent(Event);

    if(Event.Type == sf::Event::Closed) {
      App.Close();
    } else if(Event.Type == sf::Event::Resized) {
      sf::FloatRect fr(0, 0, Event.Size.Width, Event.Size.Height);
      App.SetView(sf::View(fr));
    }

    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)) {
      player->moveLeft();
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)) {
      player->moveRight();
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up)) {
      player->moveUp();
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Down)) {
      player->moveDown();
    }

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    map->draw();
    player->draw();
    App.Display();
  }

  return 0;
}
