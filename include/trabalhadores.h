/*
 * Tela dos Trabalhadores.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef WORKERS_H
#define WORKERS_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Workers : public Level, public Listener
{
public:
    Workers(const string& next = "");
    ~Workers();

    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
};

#endif
