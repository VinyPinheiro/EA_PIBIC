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
#include <ijengine/core/mousebuttoneventlistener.h>
#include <ijengine/core/keyboardeventlistener.h>

class Credits : public Level, MouseButtonEventListener, KeyboardEventListener
{
public:
    Credits(const string& next = "");
    ~Credits();

    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onKeyboardEvent(const KeyboardEvent& event);

private:
    void draw_self();
};

#endif
