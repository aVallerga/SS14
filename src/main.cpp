#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "maploader.h"
#include "player.h"

using namespace std;

int main() {
  sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SS14");

  Map *map = MapLoader::loadMap(&App, "map.png");

  Player *player = new Player(&App);

  bool keyPressed = false;
  char key;
  int preElapsedTime = 0;

  sf::Clock Clock;
  sf::Event Event;
  while(App.IsOpen()) {
    int ElapsedTime = Clock.GetElapsedTime().AsMilliseconds();    
    App.PollEvent(Event);

    if(Event.Type == sf::Event::Closed) {
      App.Close();
    } else if(Event.Type == sf::Event::Resized) {
      sf::FloatRect fr(0, 0, Event.Size.Width, Event.Size.Height);
      App.SetView(sf::View(fr));
    }

    if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)) {
      keyPressed = true;
      key = 'l';
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)) {
      keyPressed = true;
      key = 'r';
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up)) {
      keyPressed = true;
      key = 'u';
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Down)) {
      keyPressed = true;
      key = 'd';
    } else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Escape)) {
      App.Close();
    }

    if(ElapsedTime - preElapsedTime >= 500 && keyPressed == true) {
      if(key == 'l') {
        player->moveLeft();
      } else if(key == 'r') {
        player->moveRight();
      } else if(key == 'u') {
        player->moveUp();
      } else if(key == 'd') {
        player->moveDown();
      }
      key = 'a';
      preElapsedTime = ElapsedTime;
    }

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    map->draw();
    player->draw();
    App.Display();
    keyPressed = false;
  }

  return 0;
}
