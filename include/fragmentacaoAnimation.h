#ifndef FRAGMENTACAOANIMATION_H
#define FRAGMENTACAOANIMATION_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

#include <vector>

using namespace std;

#include "cano.h"

class Image;

class FragmentacaoAnimation : public Level
{
public:
    FragmentacaoAnimation(const string& next = "");
    ~FragmentacaoAnimation() {}

private:
    void draw_self();
    void update_self(unsigned long elapsed);

    int m_cano;
    vector<Cano *> m_canos;
};
#endif
