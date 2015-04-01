#ifndef TECNOLOGIAS_H
#define TECNOLOGIAS_H

#include "video.h"
#include "level.h"
#include "imagem.h"

class Technologies : public Level
{
public:
	Technologies(Video *video, Uint32 begin, Uint32 finish);
	~Technologies();
	
	bool process_event(vector<SDL_Event>& events);
	void draw(int x, int y);
	void draw(int x1, int y1, int x2, int y2, Uint32 now);

private:
	Imagem *unb;
	Imagem *fga;
	Video *video;
	Uint32 end,start;
};

#endif
