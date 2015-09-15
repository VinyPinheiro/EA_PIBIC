#ifndef AGLUTINAGEM_H
#define AGLUTINAGEM_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Aglutinagem : public Level
{
public:
  Aglutinagem(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
