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
//---------------------------------------------------------
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
//---------------------------------------------------------
#include "biocombustiveisAnimation.h"
#include "biocombustiveis.h"
//---------------------------------------------------------
#include "biodieselAnimation.h"
#include "biodiesel_prelimpeza.h"
#include "biodiesel_prelimpezaAnimation.h"
#include "biodiesel_degomagem.h"
#include "biodiesel_degomagemAnimation.h"
#include "biodiesel_neutralizacao.h"
#include "biodiesel_neutralizacaoAnimation.h"
#include "biodiesel_branqueamento.h"
#include "biodiesel_branqueamentoAnimation.h"
#include "biodiesel_desodorizacao.h"
#include "biodiesel_desodorizacaoAnimation.h"
#include "biodiesel_armazenamento.h"
#include "biodiesel_armazenamentoAnimation.h"
#include "biodiesel_transesterificacao.h"
#include "biodiesel_transesterificacaoAnimation.h"
//---------------------------------------------------------
#include "bioqueroseneAnimation.h"
#include "bioquerosene_transesterificacao.h"
#include "bioquerosene_transesterificacaoAnimation.h"
#include "bioquerosene_separacao_fase.h"
#include "bioquerosene_separacao_faseAnimation.h"
#include "bioquerosene_descarbonilacao.h"
#include "bioquerosene_descarbonilacaoAnimation.h"
#include "bioquerosene_separacao.h"
#include "bioquerosene_separacaoAnimation.h"
#include "bioquerosene_hidrogenacao.h"
#include "bioquerosene_hidrogenacaoAnimation.h"
//---------------------------------------------------------
#include "biooleoAnimation.h"
#include "biooleo_pressurizacao.h"
#include "biooleo_pressurizacaoAnimation.h"
#include "biooleo_desoxigenacao.h"
#include "biooleo_desoxigenacaoAnimation.h"
#include "biooleo_reacao_diesel.h"
#include "biooleo_reacao_dieselAnimation.h"
#include "biooleo_isomeros.h"
#include "biooleo_isomerosAnimation.h"
#include "biooleo_destilacao.h"
#include "biooleo_destilacaoAnimation.h"
//---------------------------------------------------------
#include "finalizacao.h"
#include "winner.h"

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
	}
	else if (id == "delivery")
    {
        return new Delivery("industry");
	}
	///DESPOLPA
	///------------------------------------------------------------------------------
	else if (id == "industry")
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
	///BIODIESEL
	///------------------------------------------------------------------------------
	else if(id == "biodieselAnimation")
    {
		return new BiodieselAnimation("biodiesel_prelimpeza");
	}
	else if(id == "biodiesel_prelimpeza")
    {
		return new Biodiesel_prelimpeza();
	}
	else if(id == "biodiesel_prelimpezaAnimation")
    {
		return new Biodiesel_prelimpezaAnimation("biodiesel_degomagem");
	}
	else if(id == "biodiesel_degomagem")
    {
		return new Biodiesel_degomagem();
	}
	else if(id == "biodiesel_degomagemAnimation")
    {
		return new Biodiesel_degomagemAnimation("biodiesel_neutralizacao");
	}
	else if(id == "biodiesel_neutralizacao")
    {
		return new Biodiesel_neutralizacao();
	}
	else if(id == "biodiesel_neutralizacaoAnimation")
    {
		return new Biodiesel_neutralizacaoAnimation("biodiesel_branqueamento");
	}
	else if(id == "biodiesel_branqueamento")
    {
		return new Biodiesel_branqueamento();
	}
	else if(id == "biodiesel_branqueamentoAnimation")
    {
		return new Biodiesel_branqueamentoAnimation("biodiesel_desodorizacao");
	}
	else if(id == "biodiesel_desodorizacao")
    {
		return new Biodiesel_desodorizacao();
	}
	else if(id == "biodiesel_desodorizacaoAnimation")
    {
		return new Biodiesel_desodorizacaoAnimation("biodiesel_armazenamento");
	}
	else if(id == "biodiesel_armazenamento")
    {
		return new Biodiesel_armazenamento();
	}
	else if(id == "biodiesel_armazenamentoAnimation")
    {
		return new Biodiesel_armazenamentoAnimation("biodiesel_transesterificacao");
	}
	else if(id == "biodiesel_transesterificacao")
    {
		return new Biodiesel_transesterificacao();
	}
	else if(id == "biodiesel_transesterificacaoAnimation")
    {
		return new Biodiesel_transesterificacaoAnimation("finalizacao");
	}
	///BIOQUEROSENE
	///------------------------------------------------------------------------------
	else if(id == "bioqueroseneAnimation")
    {
		return new BioqueroseneAnimation("bioquerosene_transesterificacao");
	}
	else if(id == "bioquerosene_transesterificacao")
    {
		return new Bioquerosene_transesterificacao();
	}
	else if(id == "bioquerosene_transesterificacaoAnimation")
    {
		return new Bioquerosene_transesterificacaoAnimation("bioquerosene_separacao_fase");
	}
	else if(id == "bioquerosene_separacao_fase")
    {
		return new Bioquerosene_separacao_fase();
	}
	else if(id == "bioquerosene_separacao_faseAnimation")
    {
		return new Bioquerosene_separacao_faseAnimation("bioquerosene_descarbonilacao");
	}
	else if(id == "bioquerosene_descarbonilacao")
    {
		return new Bioquerosene_descarbonilacao();
	}
	else if(id == "bioquerosene_descarbonilacaoAnimation")
    {
		return new Bioquerosene_descarbonilacaoAnimation("bioquerosene_separacao");
	}
	else if(id == "bioquerosene_separacao")
    {
		return new Bioquerosene_separacao();
	}
	else if(id == "bioquerosene_separacaoAnimation")
    {
		return new Bioquerosene_separacaoAnimation("bioquerosene_hidrogenacao");
	}
	else if(id == "bioquerosene_hidrogenacao")
    {
		return new Bioquerosene_hidrogenacao();
	}
	else if(id == "bioquerosene_hidrogenacaoAnimation")
    {
		return new Bioquerosene_hidrogenacaoAnimation("finalizacao");
	}
	///BIO OLEO
	///------------------------------------------------------------------------------
	else if(id == "biooleoAnimation")
    {
		return new BiooleoAnimation("biooleo_pressurizacao");
	}
	else if(id == "biooleo_pressurizacao")
    {
		return new Biooleo_pressurizacao();
	}
	else if(id == "biooleo_pressurizacaoAnimation")
    {
		return new Biooleo_pressurizacaoAnimation("biooleo_desoxigenacao");
	}
	else if(id == "biooleo_desoxigenacao")
    {
		return new Biooleo_desoxigenacao();
	}
	else if(id == "biooleo_desoxigenacaoAnimation")
    {
		return new Biooleo_desoxigenacaoAnimation("biooleo_reacao_diesel");
	}
	else if(id == "biooleo_reacao_diesel")
    {
		return new Biooleo_reacao_diesel();
	}
	else if(id == "biooleo_reacao_dieselAnimation")
    {
		return new Biooleo_reacao_dieselAnimation("biooleo_isomeros");
	}
	else if(id == "biooleo_isomeros")
    {
		return new Biooleo_isomeros();
	}
	else if(id == "biooleo_isomerosAnimation")
    {
		return new Biooleo_isomerosAnimation("biooleo_destilacao");
	}
	else if(id == "biooleo_destilacao")
    {
		return new Biooleo_destilacao();
	}
	else if(id == "biooleo_destilacaoAnimation")
    {
		return new Biooleo_destilacaoAnimation("finalizacao");
	}
	///------------------------------------------------------------------------------
	else if(id == "finalizacao")
    {
		return new Finalizacao("winner");
	}
	else if(id == "winner")
    {
		return new Winner("start");
	}
	
    return nullptr;
}
