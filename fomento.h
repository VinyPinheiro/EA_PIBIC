#ifndef FOMENTO_H
#define FOMENTO_H

#include "video.h"
#include "frontend.h"
#include "imagem.h"

class Fomento : public FrontEnd
{
public:
    Fomento(Video *v, Level *n = 0, Uint32 d = 3000);
	~Fomento();
	
	void draw(int x = 0, int y = 0);

private:
	Imagem *fomento;
};

#endif
