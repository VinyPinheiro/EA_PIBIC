/*
 * Tela da Escolha.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef CHOICE_H
#define CHOICE_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>
#include "question.h"

class Choice : public Level
{
public:
    Choice(const string& next = "");


private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;
};

#endif
