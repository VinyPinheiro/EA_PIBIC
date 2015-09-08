#ifndef FRAGMENTACAO_H
#define FRAGMENTACAO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Fragmentacao : public Level
{
public:
  Fragmentacao(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
