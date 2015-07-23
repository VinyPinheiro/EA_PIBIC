#ifndef DESPOLPAMENTO_H
#define DESPOLPAMENTO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Despolpamento : public Level
{
public:
  Despolpamento(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
