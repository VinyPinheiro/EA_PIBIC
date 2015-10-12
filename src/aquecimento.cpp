#include "aquecimento.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Aquecimento::Aquecimento(const string& next)
    : Level("compactacaoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase2.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","aquecimentoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Despolpa", "Aquecer briquete moldado para diminuir a umidade?"
		, button);
    add_child(question);
   
}

void
Aquecimento::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}


void
Aquecimento::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
