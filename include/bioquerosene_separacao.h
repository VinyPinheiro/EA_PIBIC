#ifndef BIOQUEROSENE_SEPARACAO_H
#define BIOQUEROSENE_SEPARACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Bioquerosene_separacao : public Level
{
public:
  Bioquerosene_separacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
