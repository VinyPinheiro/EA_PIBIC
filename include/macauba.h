/*
 * Tela inicial da simulação da macaúba.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MACAUBA_H
#define MACAUBA_H

#include <ijengine/core/level.h>
#include "question.h"

class Macauba : public Level
{
public:
    Macauba(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;
};

#endif
