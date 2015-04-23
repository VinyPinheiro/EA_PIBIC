#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "imagem.h"
#include "video.h"
#include "text.h"
#include "frontend.h"

class Presentation : public FrontEnd
{
public:	
    Presentation(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Presentation();
	void update(Uint32);
	
	void draw(int x = 0, int y = 0);

private:
	Text *menu;
	Text *start;
	Text *option;
	Text *exit;
	Imagem *earth;
	bool process_event(vector<SDL_Event>& events);
};

#endif
