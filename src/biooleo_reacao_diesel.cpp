#include "biooleo_reacao_diesel.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biooleo_reacao_diesel::Biooleo_reacao_diesel(const string& next)
    : Level("biooleo_desoxigenacaoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biooleo.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","biooleo_reacao_dieselAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Bio Óleo", "Reagir o diesel resultante com o hidrogênio?"
		, button);
    add_child(question);
}

void
Biooleo_reacao_diesel::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biooleo_reacao_diesel::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
