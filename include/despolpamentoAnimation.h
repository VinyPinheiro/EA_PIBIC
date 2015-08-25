#ifndef DESPOLPAMENTOANIMATION_H
#define DESPOLPAMENTOANIMATION_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class DespolpamentoAnimation : public Level
{
public:
  DespolpamentoAnimation(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
