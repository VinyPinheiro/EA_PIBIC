#include "finalizacao.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Finalizacao::Finalizacao(const string& next)
    : Level("", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_industry.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","biocombustiveis");
	button.emplace_back("Não","winner");
	
    question = new Question(this, "Biocombustíveis", "Deseja produzir mais algum biocombustível?"
		, button);
    add_child(question);
    
}

void
Finalizacao::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Finalizacao::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
