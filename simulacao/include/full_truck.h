/*
 * Tela de animação do Caminhao Cheio.
 *
 * Autor: Camila Ferrer
 * Data: 03/07/2015
 * Licença: LGPL. Sem copyright.
 */

#ifndef FULL_TRUCK_H
#define FULL_TRUCK_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Full_truck : public Level
{
public:
    Full_truck(const string& next = "");

private:
    void draw_self();
    void update_self(unsigned long);

    Image *truck, *co2, *rs, *ro;
    unsigned long last;
    double truck_speed;
    double co2_speed;
    double rs_speed;
    double ro_speed;

};

#endif
