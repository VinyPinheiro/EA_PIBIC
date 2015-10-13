#include "bioquerosene_descarbonilacao.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Bioquerosene_descarbonilacao::Bioquerosene_descarbonilacao(const string& next)
    : Level("bioquerosene_separacao_faseAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_bioquerosene.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","bioquerosene_descarbonilacaoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Bioquerosene", "Realizar a descarbonilação?"
		, button);
    add_child(question);
    
}

void
Bioquerosene_descarbonilacao::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Bioquerosene_descarbonilacao::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
