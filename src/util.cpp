#include "util.h"

using namespace std;

sf::Texture* Util::getTexture(string filename) {
  sf::Texture *texture = new sf::Texture;
  if(!texture->LoadFromFile(filename)) {
    cerr << "Error: Texture " << filename << " not found." << endl;
    exit(1);
  }
  return texture;
}
