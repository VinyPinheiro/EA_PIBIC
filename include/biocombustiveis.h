#ifndef BIOCOMBUSTIVEIS_H
#define BIOCOMBUSTIVEIS_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Biocombustiveis : public Level
{
public:
  Biocombustiveis(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
