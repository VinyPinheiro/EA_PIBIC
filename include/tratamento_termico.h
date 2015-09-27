#ifndef TRATAMENTO_TERMICO_H
#define TRATAMENTO_TERMICO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Tratamento_termico : public Level
{
public:
  Tratamento_termico(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
