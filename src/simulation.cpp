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
#include "despolpamento.h"
#include "despolpamentoAnimation.h"
#include "prensagem_polpa.h"
#include "prensagem_polpaAnimation.h"
#include "fragmentacao.h"
#include "fragmentacaoAnimation.h"
#include "separacao.h"
#include "separacaoAnimation.h"
#include "amendoa.h"
#include "amendoaAnimation.h"
#include "trituracao.h"
#include "trituracaoAnimation.h"
#include "aglutinagem.h"
#include "aglutinagemAnimation.h"
#include "lavagem.h"
#include "lavagemAnimation.h"
#include "compactacao.h"
#include "compactacaoAnimation.h"
#include "aquecimento.h"
#include "aquecimentoAnimation.h"
#include "tratamento_termico.h"
#include "tratamento_termicoAnimation.h"
#include "biocombustiveisAnimation.h"
#include "biocombustiveis.h"
#include "biodieselAnimation.h"
#include "bioqueroseneAnimation.h"
#include "biooleoAnimation.h"

//#include "filter.h"

#include <ijengine/util/frontend.h>

Simulation::Simulation()
    : Game("biocombustiveis")
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
        return new Industry("despolpamento");
	}
    else if(id == "despolpamento")
    {
        return new Despolpamento();
    }
    else if(id == "despolpamentoAnimation")
    {
		return new DespolpamentoAnimation("prensagem_polpa");
	}
	else if(id == "prensagem_polpa")
    {
		return new Prensagem_Polpa();
	}
	else if(id == "prensagem_polpaAnimation")
    {
		return new Prensagem_PolpaAnimation("fragmentacao");
	}
	else if(id == "fragmentacao")
    {
		return new Fragmentacao();
	}
	else if(id == "fragmentacaoAnimation")
    {
		return new FragmentacaoAnimation("separacao");
	}
	else if(id == "separacao")
    {
		return new Separacao();
	}
	else if(id == "separacaoAnimation")
    {
		return new SeparacaoAnimation("amendoa");
	}
	else if(id == "amendoa")
    {
		return new Amendoa();
	}
	else if(id == "amendoaAnimation")
    {
		return new AmendoaAnimation("trituracao");
	}
	else if(id == "trituracao")
    {
		return new Trituracao();
	}
	else if(id == "trituracaoAnimation")
    {
		return new TrituracaoAnimation("aglutinagem");
	}
	else if(id == "aglutinagem")
    {
		return new Aglutinagem();
	}
	else if(id == "aglutinagemAnimation")
    {
		return new AglutinagemAnimation("lavagem");
	}
	else if(id == "lavagem")
    {
		return new Lavagem();
	}
	else if(id == "lavagemAnimation")
    {
		return new LavagemAnimation("compactacao");
	}
	else if(id == "compactacao")
    {
		return new Compactacao();
	}
	else if(id == "compactacaoAnimation")
    {
		return new CompactacaoAnimation("aquecimento");
	}
	else if(id == "aquecimento")
    {
		return new Aquecimento();
	}
	else if(id == "aquecimentoAnimation")
    {
		return new AquecimentoAnimation("tratamento_termico");
	}
	else if(id == "tratamento_termico")
    {
		return new Tratamento_termico();
	}
	else if(id == "tratamento_termicoAnimation")
    {
		return new Tratamento_termicoAnimation("biocombustiveisAnimation");
	}
	else if(id == "biocombustiveisAnimation")
    {
		return new BiocombustiveisAnimation("biocombustiveis");
	}
	else if(id == "biocombustiveis")
    {
		return new Biocombustiveis();
	}
	else if(id == "biodieselAnimation")
    {
		return new BiodieselAnimation();
	}
	else if(id == "bioqueroseneAnimation")
    {
		return new BioqueroseneAnimation();
	}
	else if(id == "biooleoAnimation")
    {
		return new BiooleoAnimation();
	}
	
    return nullptr;
}
