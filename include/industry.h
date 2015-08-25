/*
 * Tela da Indústria.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef INDUSTRY_H
#define INDUSTRY_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Industry : public Level, public Listener
{
public:
    Industry(const string& next = "");
    ~Industry();

    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
};

#endif
