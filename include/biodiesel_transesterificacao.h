#ifndef BIODIESEL_TRANSESTERIFICACAO_H
#define BIODIESEL_TRANSESTERIFICACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_transesterificacao : public Level
{
public:
  Biodiesel_transesterificacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
