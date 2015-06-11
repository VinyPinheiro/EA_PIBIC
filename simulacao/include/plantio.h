/*
 * Tela de plantio.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef PLANTIO_H
#define PLANTIO_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Button;

class Plantio : public Level
{
public:
    Plantio(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    Button *amount, *plus, *minus;
    unsigned int seedlings;

    void draw_self();
};

#endif
