#ifndef BIODIESEL_ARMAZENAMENTO_H
#define BIODIESEL_ARMAZENAMENTO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_armazenamento : public Level
{
public:
  Biodiesel_armazenamento(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
