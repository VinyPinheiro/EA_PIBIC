#include "biodiesel_desodorizacao.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biodiesel_desodorizacao::Biodiesel_desodorizacao(const string& next)
    : Level("biodiesel_branqueametoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biodiesel.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","biodiesel_desodorizacaoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Biodiesel", "Realizar desodorização do óleo branqueado?"
		, button);
    add_child(question);
}

void
Biodiesel_desodorizacao::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biodiesel_desodorizacao::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
