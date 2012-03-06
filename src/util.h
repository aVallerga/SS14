#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Util {
  public:
    static sf::Texture* getTexture(string filename);
  private:
};

#endif
