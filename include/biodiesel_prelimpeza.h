#ifndef BIOOLEO_PRELIMPEZA_H
#define BIOOLEO_PRELIMPEZA_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_prelimpeza : public Level
{
public:
  Biodiesel_prelimpeza(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
