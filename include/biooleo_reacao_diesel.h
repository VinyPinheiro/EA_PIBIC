#ifndef BIOOLEO_REACAO_DIESEL_H
#define BIOOLEO_REACAO_DIESEL_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biooleo_reacao_diesel : public Level
{
public:
  Biooleo_reacao_diesel(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
