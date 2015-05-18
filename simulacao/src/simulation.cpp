/*
 * Implementação da classe Simulation.
 *
 * Autor: Edson Alves
 * Data: 11/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "simulation.h"
#include "titlescreen.h"
#include "credits.h"

#include <ijengine/util/frontend.h>

Simulation::Simulation()
    : Game("unb")
{
}

Level *
Simulation::load_level(const string& id)
{
    if (id == "unb")
    {
        return new FrontEnd(id, "cnpq", "res/images/unb.png", 3000,
            Color::WHITE);
    }
    else if (id == "cnpq")
    {
        return new FrontEnd(id, "classification", "res/images/cnpq_capes.jpg",
            3000, Color::WHITE);
    }
    else if (id == "classification")
    {
        return new FrontEnd(id, "title", "res/images/classification.png");
    }
    else if (id == "title")
    {
        return new TitleScreen();
    }
    else if (id == "credits")
    {
        return new Credits("title");
    }

    return nullptr;
}
