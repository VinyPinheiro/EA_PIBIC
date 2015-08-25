/*
 * Tela de preparação do solo.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SOLO_H
#define SOLO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Solo : public Level
{
public:
    Solo(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();
};

#endif
