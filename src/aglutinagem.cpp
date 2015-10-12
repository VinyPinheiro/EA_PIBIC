#include "aglutinagem.h"
#include "global.h"
#include "question.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <vector>
#include <ijengine/util/button.h>

Aglutinagem::Aglutinagem(const string& next)
    : Level("trituracaoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase2.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","aglutinagemAnimation");
	button.emplace_back("Não","gameover");

	question = new Question(this, "Despolpa", "Realizar a aglutinagem?", button);
    add_child(question);
}

void
Aglutinagem::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Aglutinagem::update_self(unsigned long )
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
