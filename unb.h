#ifndef UNB_H
#define UNB_H

#include "frontend.h"
#include "imagem.h"

class UnB : public FrontEnd
{
public:
	UnB(Video *video, Level *next = 0, Uint32 duration = 3000);
	~UnB();
	
	void draw(int x = 0, int y = 0);

private:
	Imagem *unb;
	Imagem *fga;

	void draw(int x1, int y1, int x2, int y2);
};

#endif
