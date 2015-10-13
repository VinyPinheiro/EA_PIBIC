#ifndef BIOOLEO_PRESSURIZACAO_H
#define BIOOLEO_PRESSURIZACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biooleo_pressurizacao : public Level
{
public:
  Biooleo_pressurizacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
