#ifndef ENERGY_H
#define ENERGY_H

#include <ijengine/core/image.h>
#include "factory_component.h"

class Energy : public FactoryComponent
{
public:
   Energy(Object *parent, double x, double y);

    void start();
    bool stopped() const;

private:
    void update_self(unsigned long elapsed);
    void draw_self();

    bool m_working;
    Image *m_coin;
    double m_target;
    double m_initial_time;
};

#endif
