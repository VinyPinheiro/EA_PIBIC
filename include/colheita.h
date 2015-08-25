/*
 * Tela de Colheita.
 *
 * Autor: Camila Ferrer
 * Data: 02/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef COLHEITA_H
#define COLHEITA_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Colheita : public Level
{
public:
    Colheita(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);


private:
    void draw_self();
};

#endif
