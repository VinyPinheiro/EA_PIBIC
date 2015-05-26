/*
 * Arquivo principal da simulação.
 *
 * Autor: Edson Alves
 * Data: 11/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "simulation.h"

#include <iostream>

using namespace std;

int main(int, char *[])
{
    try
    {
        Simulation simulation;
        simulation.init("Simulação", 1200, 800);
        simulation.run();
    } catch (Exception ex)
    {
        cerr << ex.message() << endl;
        return -1;
    }

    return 0;
}
