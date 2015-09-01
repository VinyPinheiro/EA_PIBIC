#ifndef GEAR_H
#define GEAR_H

#include <ijengine/core/level.h>
#include <ijengine/core/animation.h>

#include "factory_component.h"
#include "coin.h"

#include <list>

using std::list;

class Gear : public FactoryComponent
{
public:
    Gear(Object *parent, double x, double y);
    ~Gear() {}

    void start();
    bool stopped() const;

private:
    void update_self(unsigned long elapsed);
    void draw_self();

    bool m_working;
    list<Animation> m_animations;
    Coin *m_coin;
    int m_coins;
};

#endif
