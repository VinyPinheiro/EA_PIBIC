#ifndef UNB_H
#define UNB_H

#include "video.h"
#include "level.h"
#include "imagem.h"

class UnB : public Level
{
public:
	UnB(Video *video, Uint32 begin, Uint32 finish);
	~UnB();
	
	bool process_event(vector<SDL_Event>& events);
	void draw(int x, int y);
	void draw(int x1, int y1, int x2, int y2, Uint32 now);

private:
	Imagem *unb;
	Imagem *fga;
	Video *video;
	Uint32 end;
};

#endif
