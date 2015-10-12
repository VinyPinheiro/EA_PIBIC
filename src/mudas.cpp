/*
 * Implementação da classe Mudas.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "mudas.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Mudas::Mudas(const string& next)
    : Level("mudas", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    unsigned int distance = env->canvas->w() / 9;
    unsigned int delta = 50;

    for (unsigned int i = 0; i < seedlings_amount; ++i)
    {
        Image *sprout = new Image(this, "res/images/sprout.png");

        if (sprout)
        {
            double x = i*distance + delta;
            sprout->set_position(x - sprout->w() / 2, env->canvas->h() - sprout->h() - 100);
        }

        add_child(sprout);
    }
    
	vector<pair<string, string> > button;

	button.emplace_back("Sim","adubo");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Plantio", "Colocar adubo, pesticida e água?"
		, button);
    add_child(question);
}

void
Mudas::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Mudas::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
