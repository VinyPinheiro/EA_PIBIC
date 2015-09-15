#ifndef SEPARACAO_H
#define SEPARACAO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Separacao : public Level
{
public:
  Separacao(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
