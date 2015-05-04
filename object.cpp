#include "object.h"

Object::Object(const string& id, int x, int y, Object * parent)
    : m_id(id), m_parent(parent), m_x(x), m_y(y)
{
}

Object::~Object()
{
    while (not m_children.empty())
    {
        Object *obj = m_children.back();
        m_children.pop_back();
        delete obj;
    }
}

Object *
Object::parent() const
{
    return m_parent;
}

void
Object::add_children(Object *children)
{
    if (children)
    {
        m_children.push_back(children);
    }
}

void
Object::remove_children(Object *children)
{
    m_children.remove(children);
}

void
Object::update(unsigned long elapsed)
{
    for (auto children : m_children)
    {
        children->update(elapsed);
    }

    update_self(elapsed);
}

void
Object::draw()
{
    draw_self();

    for (auto children : m_children)
    {
        children->draw();
    }
}

int
Object::x() const
{
    return m_x;
}

int
Object::y() const
{
    return m_y;
}


void
Object::set_position(int x, int y)
{
    m_x = x;
    m_y = y;
}

void
Object::update_self(unsigned long)
{
}

void
Object::draw_self()
{
}
