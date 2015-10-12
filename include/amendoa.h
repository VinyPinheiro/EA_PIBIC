#ifndef AMENDOA_H
#define AMENDOA_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Amendoa : public Level
{
public:
  Amendoa(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
