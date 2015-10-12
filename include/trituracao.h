#ifndef TRITURACAO_H
#define TRITURACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Trituracao : public Level
{
public:
  Trituracao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
