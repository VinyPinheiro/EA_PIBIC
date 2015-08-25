/*
 * Tela de animação da Entrega do Caminhao Cheio.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */

#ifndef DELIVERY_H
#define DELIVERY_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Delivery : public Level, public Listener
{
public:
    Delivery(const string& next = "");
    ~Delivery();
    bool on_event(const MouseButtonEvent& event);
    bool on_event(const KeyboardEvent& event);


private:
    void draw_self();
    void update_self(unsigned long);

    Image *truck, *co2;
    unsigned long last;
    double truck_speed;
    double co2_speed;

};

#endif
