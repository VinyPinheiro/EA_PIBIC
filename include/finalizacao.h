#ifndef FINALIZACAO_H
#define FINALIZACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Finalizacao : public Level
{
public:
  Finalizacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
