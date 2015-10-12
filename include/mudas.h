/*
 * Tela das Mudas.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef MUDAS_H
#define MUDAS_H

#include <ijengine/core/level.h>
#include "question.h"

class Mudas : public Level
{
public:
    Mudas(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;
};

#endif
