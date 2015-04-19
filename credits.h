#ifndef CREDITS_H
#define CREDITS_H

#include "imagem.h"
#include "video.h"
#include "frontend.h"

class Credits : public FrontEnd
{
public:
	Credits(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Credits();

	void draw(int x = 0, int y = 0);

private:
	Imagem *credits;
	void draw(int x1, int y1,int x2, int y2,int x3, int y3);
};

#endif
