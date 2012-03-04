#ifndef OBJECT_H
#define OBJECT_H

using namespace std;

class Object {
  protected:
  public:
    Object();
    ~Object();
    char getId();
  protected:
    char m_id;
};

#endif
