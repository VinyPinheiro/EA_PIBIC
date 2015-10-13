#ifndef WINNER_H
#define WINNER_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Winner : public Level, public Listener
{
public:
    Winner(const string& next = "");
    ~Winner();

    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
};

#endif
