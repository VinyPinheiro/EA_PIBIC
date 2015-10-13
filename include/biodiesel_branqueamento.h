#ifndef BIODIESEL_BRANQUEAMENTO_H
#define BIODIESEL_BRANQUEAMENTO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_branqueamento : public Level
{
public:
  Biodiesel_branqueamento(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
