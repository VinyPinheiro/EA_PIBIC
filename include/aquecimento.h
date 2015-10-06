#ifndef AQUECIMENTO_H
#define AQUECIMENTO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Aquecimento : public Level
{
public:
  Aquecimento(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
