#ifndef BIOQUEROSENE_HIDROGENACAO_H
#define BIOQUEROSENE_HIDROGENACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Bioquerosene_hidrogenacao : public Level
{
public:
  Bioquerosene_hidrogenacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
