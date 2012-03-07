#include "util.h"

using namespace std;

map<string, sf::Texture*> Util::m_textures = Util::initMap();

map<string, sf::Texture*> Util::initMap() {
  map<string, sf::Texture*> new_map;
  return new_map;
}

sf::Texture* Util::getTexture(string filename) {
  map<string, sf::Texture*>::iterator it;
  it = m_textures.find(filename);

  if(it == m_textures.end()) {
    cout << filename << " not loaded. Loading to memory" << endl;
    sf::Texture *texture = new sf::Texture;
    if(!texture->LoadFromFile(filename)) {
      cerr << "Error: Texture " << filename << " not found." << endl;
      exit(1);
    }
    m_textures.insert( pair<string, sf::Texture*>(filename, texture));
    return texture;
  } else {
    return it->second;
  }
}
