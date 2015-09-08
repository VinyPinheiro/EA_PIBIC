#ifndef PRENSAGEM_POLPA_H
#define PRENSAGEM_POLPA_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Prensagem_Polpa : public Level
{
public:
  Prensagem_Polpa(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
