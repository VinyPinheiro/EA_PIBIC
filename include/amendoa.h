#ifndef AMENDOA_H
#define AMENDOA_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Amendoa : public Level
{
public:
  Amendoa(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
