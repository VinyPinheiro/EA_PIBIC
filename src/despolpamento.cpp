#include "despolpamento.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Despolpamento::Despolpamento(const string& next)
    : Level("industry", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());


    Image *image = new Image(this, "res/images/background_despolpa_fase1.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","despolpamentoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Despolpa", "Separar a polpa da casca, do endocarpo e da amêndoa?"
		, button);
    add_child(question);
        
}

void
Despolpamento::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Despolpamento::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
