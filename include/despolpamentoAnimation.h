#ifndef DESPOLPAMENTOANIMATION_H
#define DESPOLPAMENTOANIMATION_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

#include <vector>

using namespace std;

#include "cano.h"

class Image;

class DespolpamentoAnimation : public Level
{
public:
    DespolpamentoAnimation(const string& next = "");
    ~DespolpamentoAnimation() {}

private:
    void draw_self();
    void update_self(unsigned long elapsed);

    int m_cano;
    vector<Cano *> m_canos;
};
#endif
