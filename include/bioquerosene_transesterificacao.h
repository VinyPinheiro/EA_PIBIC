#ifndef BIOQUEROSENE_TRANSESTERIFICACAO_H
#define BIOQUEROSENE_TRANSESTERIFICACAO_H

#include <ijengine/core/level.h>
#include "question.h"

class Image;

class Bioquerosene_transesterificacao : public Level
{
public:
  Bioquerosene_transesterificacao(const string& next = "");

private:
	void update_self(unsigned long elapsed);
	void draw_self();

	Question *question;

};
#endif
