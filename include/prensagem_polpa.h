#ifndef PRENSAGEM_POLPA_H
#define PRENSAGEM_POLPA_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Prensagem_Polpa : public Level
{
public:
  Prensagem_Polpa(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
