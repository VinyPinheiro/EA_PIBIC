#ifndef TRITURACAO_H
#define TRITURACAO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Trituracao : public Level
{
public:
  Trituracao(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
