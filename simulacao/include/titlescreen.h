/*
 * Tela de apresentação da simulação.
 *
 * Autor: Edson Alves
 * Data: 13/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <ijengine/core/level.h>

class TitleScreen : public Level
{
public:
    TitleScreen();
    virtual ~TitleScreen();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif
