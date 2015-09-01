#ifndef CANO_H
#define CANO_H

#include <ijengine/core/level.h>
#include <ijengine/core/animation.h>

class Cano : public Object
{
public:
    typedef enum { RETO, CURVO, T } Tipo;

    Cano(Object *parent, double x, double y, Tipo tipo);

    void fill();
    bool filled() const;

private:
    void update_self(unsigned long elapsed);
    void draw_self();

    Animation *m_animation;
    bool m_filling;
};

#endif
