#ifndef BIOQUEROSENE_DESCARBONILACAO_H
#define BIOQUEROSENE_DESCARBONILACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Bioquerosene_descarbonilacao : public Level
{
public:
  Bioquerosene_descarbonilacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
