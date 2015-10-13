#ifndef BIODIESEL_NEUTRALIZACAO_H
#define BIODIESEL_NEUTRALIZACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_neutralizacao : public Level
{
public:
  Biodiesel_neutralizacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
