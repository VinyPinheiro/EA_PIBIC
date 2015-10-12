#include "tratamento_termico.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Tratamento_termico::Tratamento_termico(const string& next)
    : Level("aquecimentoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase2.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","tratamento_termicoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Despolpa", "Fazer tratamento térmico do briquete moldado?"
		, button);
    add_child(question);
    
}

void
Tratamento_termico::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Tratamento_termico::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
