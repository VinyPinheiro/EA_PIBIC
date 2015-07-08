/*
 * Tela de animação dos Trabalhadores.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef WORK_H
#define WORK_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Work : public Level, public Listener
{
public:
    Work(const string& next = "");
    ~Work();
    
    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
    void update_self(unsigned long);

    Image *tractor, *co2;
    unsigned long last;
    double tractor_speed;
    double co2_speed;
};

#endif
