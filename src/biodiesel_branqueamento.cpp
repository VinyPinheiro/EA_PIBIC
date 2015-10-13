#include "biodiesel_branqueamento.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biodiesel_branqueamento::Biodiesel_branqueamento(const string& next)
    : Level("biodiesel_neutralizacaoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biodiesel.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","biodiesel_branqueamentoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Biodiesel", "Fazer o branqueamento do óleo neutro?"
		, button);
    add_child(question);
}

void
Biodiesel_branqueamento::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biodiesel_branqueamento::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
