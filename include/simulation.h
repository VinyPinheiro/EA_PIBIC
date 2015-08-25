/*
 * Classe que representa a simulacao.
 *
 * Autor: Edson Alves
 * Data: 11/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SIMULATION_H
#define SIMULATION_H

#include <ijengine/core/game.h>

class Simulation : public Game
{
public:
    Simulation();

private:
    Level * load_level(const string& id);
};

#endif
