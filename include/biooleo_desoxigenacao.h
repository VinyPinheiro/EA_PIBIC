#ifndef BIOOLEO_DESOXIGENACAO_H
#define BIOOLEO_DESOXIGENACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biooleo_desoxigenacao : public Level
{
public:
  Biooleo_desoxigenacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
