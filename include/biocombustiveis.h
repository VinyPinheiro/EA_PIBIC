#ifndef BIOCOMBUSTIVEIS_H
#define BIOCOMBUSTIVEIS_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Biocombustiveis : public Level
{
public:
  Biocombustiveis(const string& next = "");
  bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();

};
#endif
