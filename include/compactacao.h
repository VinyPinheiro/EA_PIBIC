#ifndef COMPACTACAO_H
#define COMPACTACAO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Compactacao : public Level
{
public:
  Compactacao(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
