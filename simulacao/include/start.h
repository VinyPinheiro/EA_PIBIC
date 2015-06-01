#ifndef START_H
#define START_H

#include <ijengine/core/level.h>

class Start : public Level
{
public:
    Start();
    virtual ~Start() {}

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
