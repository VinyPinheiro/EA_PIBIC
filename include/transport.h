/*
 * Tela de animação do trator.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Transport : public Level
{
public:
    Transport(const string& next = "");

private:
    void draw_self();
    void update_self(unsigned long);

    Image *tractor, *rs, *co2;
    unsigned long last;
    double tractor_speed;
    double co2_speed;
    double rs_speed;
};

#endif
