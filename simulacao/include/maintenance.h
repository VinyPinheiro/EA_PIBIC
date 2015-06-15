/*
 * Tela de Manutenção.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Maintenance : public Level
{
public:
    Maintenance(const string& next = "");

    bool on_message(Object *object, MessageID id, Parameters);

private:
    void draw_self();
};

#endif
