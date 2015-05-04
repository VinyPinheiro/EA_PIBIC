#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <list>

using std::string;
using std::list;

class Object
{
public:
    Object(const string& id, int x, int y, Object * parent = nullptr);
    virtual ~Object();

    Object * parent() const;

    void add_children(Object *children);
    void remove_children(Object *children);

    void update(unsigned long elapsed);
    void draw();

    int x() const;
    int y() const;
    void set_position(int x, int y);

protected:
    string m_id;
    Object *m_parent;
    int m_x, m_y;
    list<Object *> m_children;

    virtual void update_self(unsigned long elapsed);
    virtual void draw_self();
};

#endif
