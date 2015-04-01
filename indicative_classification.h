#ifndef INDICATIVE_CLASSIFICATION_H
#define INDICATIVE_CLASSIFICATION_H

#include "video.h"
#include "level.h"
#include "imagem.h"

class Indicative_classification : public Level
{
public:
	Indicative_classification(Video *video, Uint32 begin, Uint32 finish);
	~Indicative_classification();
	
	bool process_event(vector<SDL_Event>& events);
	void draw(int x, int y);
	void draw(int x, int y, Uint32 now);

private:
	Imagem *classification;
	Video *video;
	Uint32 end,start;
};

#endif
