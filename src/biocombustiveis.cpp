#include "biocombustiveis.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biocombustiveis::Biocombustiveis(const string& next)
    : Level("biocombustiveisAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biocombustiveis.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Biodiesel","biodieselAnimation");
	button.emplace_back("Bioquerosene","bioqueroseneAnimation");
	button.emplace_back("Bio Óleo","biooleoAnimation");
	
    question = new Question(this, "Biocombustíveis", "Qual biocombustível deseja produzir?"
		, button);
    add_child(question);
}

void
Biocombustiveis::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biocombustiveis::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
