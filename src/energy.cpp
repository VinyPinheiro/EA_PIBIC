#include "energy.h"

#include <ijengine/core/image.h>

Energy::Energy(Object *parent, double x, double y)
    : FactoryComponent(parent, "coin", x, y), m_working(false)
{
    m_coin = new Image(this, "res/images/energy.png");
    add_child(m_coin);
    m_target = y + 100;
    m_initial_time = 0;
}

void
Energy::start()
{
    set_y(m_target - 100);
    m_working = true;
}

void
Energy::update_self(unsigned long elapsed)
{
    if (m_initial_time == 0)
        m_initial_time = elapsed;

    double delta = (elapsed - m_initial_time)/1000.0;

    m_initial_time = elapsed;

    if (m_working)
    {
        set_y(y() + 100*delta);

        if (y() >= m_target)
            m_working = false;
    } 

    m_coin->set_position(x(), y());
}

void
Energy::draw_self()
{
}

bool
Energy::stopped() const
{
    return not m_working;
}
