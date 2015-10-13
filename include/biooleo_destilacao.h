#ifndef BIOOLEO_DESTILACAO_H
#define BIOOLEO_DESTILACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biooleo_destilacao : public Level
{
public:
  Biooleo_destilacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
