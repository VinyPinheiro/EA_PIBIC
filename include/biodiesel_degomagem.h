#ifndef BIODIESEL_DEGOMAGEM_H
#define BIODIESEL_DEGOMAGEM_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_degomagem : public Level
{
public:
  Biodiesel_degomagem(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
