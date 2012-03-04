#include "object.h"

using namespace std;

Object::Object() {
  m_id = 'o';
}

Object::~Object() {

}

char Object::getId() {
  return m_id;
}
