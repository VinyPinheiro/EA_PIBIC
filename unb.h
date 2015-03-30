#ifndef UNB_H
#define UNB_H

#include "video.h"
#include "level.h"
#include "imagem.h"

class UnB : public Level
{
public:
	UnB(Video *video);
	~UnB();
	
	bool process_event(vector<SDL_Event>& events);
	void draw(int x, int y);

private:
	Imagem *unb;
	Imagem *fga;
	Video *video;
	bool visible;
};

#endif
