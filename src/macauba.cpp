/*
 * Implementação da classe Macauba.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "macauba.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Macauba::Macauba(const string& next)
    : Level("macauba", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    
    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

	vector<pair<string, string> > button;

	button.emplace_back("Iniciar","choice");
	button.emplace_back("Voltar","start");
	
    question = new Question(this, "Variáveis Ambientais nos Processos Produtíveis",
		"Biocombustível - Macaúba"
		, button);
    add_child(question);
    
}

void
Macauba::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Macauba::update_self(unsigned long)
{
	if(question->finished())
	{
		this->set_next(question->next());
		this->finish();
	}
}
