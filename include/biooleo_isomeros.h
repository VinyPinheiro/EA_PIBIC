#ifndef BIOOLEO_ISOMEROS_H
#define BIOOLEO_ISOMEROS_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biooleo_isomeros : public Level
{
public:
  Biooleo_isomeros(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
