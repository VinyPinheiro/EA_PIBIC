#ifndef TECNOLOGIAS_H
#define TECNOLOGIAS_H

#include "imagem.h"
#include "video.h"
#include "frontend.h"

class Technologies : public FrontEnd
{
public:	
    Technologies(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Technologies();
	
	void draw(int x = 0, int y = 0);

private:
	Imagem *sdl;
	Imagem *inkscape;

    void draw(int x1, int y1,int x2, int y2);
};

#endif
