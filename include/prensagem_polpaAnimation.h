#ifndef PRENSAGEM_POLPAANIMATION_H
#define PRENSAGEM_POLPAANIMATION_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

#include <vector>

using namespace std;

#include "cano.h"

class Image;

class Prensagem_PolpaAnimation : public Level
{
public:
    Prensagem_PolpaAnimation(const string& next = "");
    ~Prensagem_PolpaAnimation() {}

private:
    void draw_self();
    void update_self(unsigned long elapsed);

    int m_cano;
    vector<Cano *> m_canos;
};
#endif
