#ifndef LAVAGEM_H
#define LAVAGEM_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Lavagem : public Level
{
public:
  Lavagem(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
