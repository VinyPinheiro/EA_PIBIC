#ifndef AGLUTINAGEM_H
#define AGLUTINAGEM_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Aglutinagem : public Level
{
public:
  Aglutinagem(const string& next = "");

private:
    void draw_self();
	void update_self(unsigned long x);
	Question *question;

};
#endif
