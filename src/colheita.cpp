/*
 * Implementação da classe Colheita.
 *
 * Autor: Camila Ferrer
 * Data: 02/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "colheita.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <vector>

#include <ijengine/util/button.h>

Colheita::Colheita(const string& next)
    : Level("colheita", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    
	Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    unsigned int distance = env->canvas->w() / 9;
    unsigned int delta = 50;

    for (unsigned int i = 0; i < seedlings_amount; ++i)
    {
        Image *tree = new Image(this, "res/images/macauba.png");

        if (tree)
        {
            double x = i*distance + delta;
            tree->set_position(x - tree->w() / 2, env->canvas->h() - tree->h() - 100);
        }

        add_child(tree);
    }
 	
	vector<pair<string, string> > button;

	button.emplace_back("Sim","empty_truck");
	button.emplace_back("Não","gameover");
	
    question = new Question(this, "Colheita", "Colher macaúbas maduras?"
		, button);

	add_child(question);
}

void
Colheita::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Colheita::update_self(unsigned long x)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
