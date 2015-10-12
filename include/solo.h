/*
 * Tela de preparação do solo.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef SOLO_H
#define SOLO_H

#include <ijengine/core/level.h>
#include "question.h"

class Solo : public Level
{
public:
    Solo(const string& next = "");

private:
	void update_self(unsigned long elapsed);
    void draw_self();
    
	Question *question;
};

#endif
