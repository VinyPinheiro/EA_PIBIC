#ifndef CANO_H
#define CANO_H

#include <ijengine/core/level.h>
#include <ijengine/core/animation.h>

#include "factory_component.h"

class Cano : public FactoryComponent
{
public:
    typedef enum { RETO1, RETO2, RETO3, RETO4, CURVO1, CURVO2, CURVO3, CURVO4, CURVO5, CURVO6, CURVO7, CURVO8, T } Tipo;

    Cano(Object *parent, double x, double y, Tipo tipo);

    void start();
    bool stopped() const;

private:
    void update_self(unsigned long elapsed);
    void draw_self();

    Animation *m_animation;
    bool m_filling;
};

#endif
