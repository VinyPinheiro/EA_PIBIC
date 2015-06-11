/*
 * Tela inicial da simulação da macaúba.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MACAUBA_H
#define MACAUBA_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Macauba : public Level
{
public:
    Macauba(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();
};

#endif
