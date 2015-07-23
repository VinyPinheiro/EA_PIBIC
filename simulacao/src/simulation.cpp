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
#include "choice.h"
#include "solo.h"
#include "gameover.h"
#include "tractor.h"
#include "plantio.h"
//#include "trabalhadores.h"
#include "work.h"
#include "mudas.h"
#include "adubo.h"
#include "maintenance.h"
#include "arvores.h"
#include "colheita.h"
#include "empty_truck.h"
#include "full_truck.h"
#include "delivery.h"
#include "industry.h"
#include "filter.h"
#include "despolpamento.h"

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
    else if (id == "start")
	{
		return new Start();
	} else if (id == "macauba")
    {
        return new Macauba();
    } else if (id == "choice")
    {
        return new Choice();
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
    } else if (id == "work")
    {
        return new Work("mudas");
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
    } else if (id == "colheita")
    {
        return new Colheita();
    } else if (id == "empty_truck")
    {
        return new Empty_truck("full_truck");
	} else if (id == "full_truck")
    {
        return new Full_truck("delivery");
	} else if (id == "delivery")
    {
        return new Delivery("industry");
	} else if (id == "industry")
    {
        return new Industry("filter");
	}else if(id=="filter")
      {
        return new Filter("despolpamento");
       }
  else if(id == "despolpamento")
  {
    return new Despolpamento("start");
  }

    return nullptr;
}
