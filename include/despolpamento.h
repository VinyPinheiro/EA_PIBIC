#ifndef DESPOLPAMENTO_H
#define DESPOLPAMENTO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Despolpamento : public Level
{
public:
  Despolpamento(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
