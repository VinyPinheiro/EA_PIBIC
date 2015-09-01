#include "gear.h"
#include "coin.h"

#include <ijengine/core/image.h>

Gear::Gear(Object *parent, double x, double y)
    : FactoryComponent(parent, "gear", x, y), m_working(false)
{
    Image *machine = new Image(this, "res/images/machine.png");
    machine->set_position(x, y);

    m_coin = new Coin(this, x - 23 + machine->w() / 2, y - 60);

    add_child(m_coin);
    add_child(machine);

    m_coins = 0;
}

void
Gear::start()
{
    m_coin->start();
    m_working = true;
}

void
Gear::update_self(unsigned long)
{
    if (m_working and m_coins < 3)
    {
        if (m_coin->stopped())
        {
            ++m_coins;

            if (m_coins < 3)
                m_coin->start();
        }
    }
}

void
Gear::draw_self()
{
/*    if (m_animation)
    {
        m_animation->draw(x(), y());
    } */
}

bool
Gear::stopped() const
{
    return false;
}
