/*
 * Tela de animação do Caminhao.
 *
 * Autor: Camila Ferrer
 * Data: 02/07/2015
 * Licença: LGPL. Sem copyright.
 */

#ifndef EMPTY_TRUCK_H
#define EMPTY_TRUCK_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Empty_truck : public Level, public Listener
{
public:
    Empty_truck(const string& next = "");
    ~Empty_truck();
    
    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
    void update_self(unsigned long);

    Image *truck, *co2;
    unsigned long last;
    double truck_speed;
    double co2_speed;


};

#endif
