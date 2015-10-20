#ifndef BIODIESEL_DESODORIZACAO_H
#define BIODIESEL_DESODORIZACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biodiesel_desodorizacao : public Level
{
public:
  Biodiesel_desodorizacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
