#include "biooleo_pressurizacao.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biooleo_pressurizacao::Biooleo_pressurizacao(const string& next)
    : Level("biocombustiveis", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biooleo.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Sim","biooleo_pressurizacaoAnimation");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Bio Óleo", "Realizar o processo de pressurização do óleo vegetal?"
		, button);
    add_child(question);
    
}

void
Biooleo_pressurizacao::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biooleo_pressurizacao::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
