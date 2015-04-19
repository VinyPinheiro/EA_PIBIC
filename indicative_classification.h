#ifndef INDICATIVE_CLASSIFICATION_H
#define INDICATIVE_CLASSIFICATION_H

#include "imagem.h"
#include "video.h"
#include "frontend.h"

class Indicative_classification : public FrontEnd
{
public:
	Indicative_classification(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Indicative_classification();

	void draw(int x = 0, int y = 0);

private:
	Imagem *classification;
};

#endif
