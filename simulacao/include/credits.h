/*
 * Tela de créditos da simulação.
 *
 * Autor: Edson Alves
 * Data: 17/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef CREDITS_H
#define CREDITS_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Credits : public Level, public Listener
{
public:
    Credits(const string& next = "");
    ~Credits();

    bool on_event(const MouseButtonEvent& event);
    bool on_event(const KeyboardEvent& event);

private:
    void draw_self();
};

#endif
