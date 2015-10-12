#ifndef TRATAMENTO_TERMICO_H
#define TRATAMENTO_TERMICO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Tratamento_termico : public Level
{
public:
  Tratamento_termico(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
