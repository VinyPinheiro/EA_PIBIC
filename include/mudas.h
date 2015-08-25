/*
 * Tela das Mudas.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MUDAS_H
#define MUDAS_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Mudas : public Level
{
public:
    Mudas(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();
};

#endif
