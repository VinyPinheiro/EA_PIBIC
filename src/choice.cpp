/*
 * Adicionando a classe Question.
 *
 * Autor: Vinicius Pinheiro
 * Data: 25/09/2015
 * Licença: LGPL. Sem copyright.
 */
#include "choice.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <iostream>
#include <ijengine/util/button.h>

Choice::Choice(const string& next)
    : Level("choice", next)
{
    Image *image = new Image(this, "res/images/background.png");
    add_child(image);
	
	vector<pair<string, string> > button;

	button.emplace_back("Extrativismo","colheita");
	button.emplace_back("Plantio","solo");
	
    question = new Question(this, "Escolha de Produção da Macaúba", "Qual a forma de extração?"
		, button);
    add_child(question);
}

void
Choice::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Choice::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
