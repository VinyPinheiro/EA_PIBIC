#include "fomento.h"

Fomento::Fomento(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	fomento = new Imagem(video, "imgs/cnpq_capes.jpg");
}

Fomento::~Fomento()
{
	delete fomento;
}
	
void 
Fomento::draw(int, int)
{
    fomento->draw(38, 175);
}

