#include "indicative_classification.h"

Indicative_classification::Indicative_classification(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	classification = new Imagem(video, "imgs/indicative_classification.png");
}

Indicative_classification::~Indicative_classification()
{
	delete classification;
}

void
Indicative_classification::draw(int , int )
{
	classification->draw(0,400);
}
