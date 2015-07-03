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
#include "start.h"
#include "macauba.h"
#include "solo.h"
#include "gameover.h"
#include "tractor.h"
#include "plantio.h"
#include "trabalhadores.h"
#include "mudas.h"
#include "adubo.h"
#include "maintenance.h"
#include "arvores.h"

#include <ijengine/util/frontend.h>

Simulation::Simulation()
    : Game("plantio")
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
    else if (id == "start")
	{
		return new Start();
	} else if (id == "macauba")
    {
        return new Macauba();
    } else if (id == "solo")
    {
        return new Solo();
    } else if (id == "gameover")
    {
        return new GameOver("start");
    } else if (id == "trator")
    {
        return new Tractor("plantio");
    } else if (id == "plantio")
    {
        return new Plantio();
    } else if (id == "trabalhadores")
    {
        return new Workers("mudas");
    } else if (id == "mudas")
    {
        return new Mudas();
    } else if (id == "adubo")
    {
        return new Adubo("maintenance");
    } else if (id == "maintenance")
    {
        return new Maintenance();
    } else if (id == "arvores")
    {
        return new Arvores("colheita");
    }

    return nullptr;
}
