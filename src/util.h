#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;

class Util {
  public:
    static sf::Texture* getTexture(string filename);
    static map<string, sf::Texture*> initMap();
  private:
    static map<string, sf::Texture*> m_textures;
};

#endif
