#ifndef FOMENTO_H
#define FOMENTO_H

#include "video.h"
#include "level.h"
#include "imagem.h"

class Fomento : public Level
{
public:
	Fomento(Video *video, Uint32 begin, Uint32 finish);
	~Fomento();
	
	bool process_event(vector<SDL_Event>& events);
	void draw(int x, int y);
	void draw(int x, int y, Uint32 now);

private:
	Imagem *fomento;
	Video *video;
	Uint32 end;
};

#endif
