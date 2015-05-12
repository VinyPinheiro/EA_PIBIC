/*
 * Implementação da classe Simulation.
 *
 * Autor: Edson Alves
 * Data: 20/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "simulation.h"

#include <util/frontend.h>
//#include "titlescreen.h"
//#include "stage.h"

Simulation::Simulation()
    : Game("unb")
{
}

Level *
Simulation::load_level(const string& id)
{
    if (id == "unb")
    {
        return new FrontEnd("cnpq", "res/images/unb.png", 3000, Color::WHITE);
    }
    else if (id == "cnpq")
    {
        return new FrontEnd("classification", "res/images/cnpq_capes.jpg",
            3000, Color::WHITE);
    }
    else if (id == "classification")
    {
        return new FrontEnd("", "res/images/classification.png");
    }
/*    else if (id == "title")
    {
        return new TitleScreen();
    } else if (id == "stage1")
    {
        return new Stage("stage1");
    }
*/
    return nullptr;
}
