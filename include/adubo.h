/*
 * Tela de animação do Adubo de Mudas.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef ADUBO_H
#define ADUBO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Adubo : public Level, public Listener
{
public:
    Adubo(const string& next = "");
    ~Adubo();

    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
    void update_self(unsigned long);

    Image *rs, *fertilizer, *pesticide, *h2o;

    unsigned long start;
    unsigned long last;
    double rs_speed;
    double fertilizer_speed;
    double pesticide_speed;
    double h2o_speed;
};

#endif
