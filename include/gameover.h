/*
 * Tela de game over.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class GameOver : public Level, public Listener
{
public:
    GameOver(const string& next = "");
    ~GameOver();

    bool on_event(const KeyboardEvent& event);
    bool on_event(const MouseButtonEvent& event);

private:
    void draw_self();
};

#endif
