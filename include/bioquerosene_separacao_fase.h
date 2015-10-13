#ifndef BIOQUEROSENE_SEPARACAO_FASE_H
#define BIOQUEROSENE_SEPARACAO_FASE_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Bioquerosene_separacao_fase : public Level
{
public:
  Bioquerosene_separacao_fase(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
