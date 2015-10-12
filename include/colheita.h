/*
 * Tela de Colheita.
 *
 * Autor: Camila Ferrer
 * Data: 02/07/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef COLHEITA_H
#define COLHEITA_H

#include <ijengine/core/level.h>
#include "question.h"

class Colheita : public Level
{
public:
    Colheita(const string& next = "");

private:
    void draw_self();
	void update_self(unsigned long x);
	Question *question;
};

#endif
