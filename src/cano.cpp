#include "cano.h"

Cano::Cano(Object *parent, double x, double y, Tipo tipo)
    : Object(parent, "cano", x, y)
{
    switch (tipo) {
    case RETO:
        m_animation = new Animation("res/images/canoreto.png", 0, 0, 80, 40, 6, 150);
        break;

    default:
        m_animation = nullptr;
    }

    m_filling = false;
}

void
Cano::fill()
{
    m_filling = true;
}

void
Cano::update_self(unsigned long elapsed)
{
    if (m_filling and m_animation)
    {
        m_animation->update(elapsed);
    }
}

void
Cano::draw_self()
{
    if (m_animation)
    {
        m_animation->draw(x(), y());
    }
}

bool
Cano::filled() const
{
    return m_animation && m_animation->is_done();
}
