/*
 * Tela da Escolha.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef CHOICE_H
#define CHOICE_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Choice : public Level
{
public:
    Choice(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();
};

#endif
