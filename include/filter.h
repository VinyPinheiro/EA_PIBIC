/*
 * Tela de animação do filtro.
 *
 * Autor: Gesiel Freitas
 * Data: 03/07/2015
 * Licença: LGPL. Sem copyright.
 */

#ifndef FILTER_H
#define FILTER_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Filter : public Level
{
public:
    Filter(const string& next = "");

private:
    void draw_self();
    void update_self(unsigned long);

    Image *filter, *co2, *rs, *brine;
    unsigned long last;
    double brine_speed;
    double co2_speed;
    double rs_speed;
    double filter_speed;

};

#endif
