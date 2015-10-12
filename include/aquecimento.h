#ifndef AQUECIMENTO_H
#define AQUECIMENTO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Aquecimento : public Level
{
public:
  Aquecimento(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;
};
#endif
