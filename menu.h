#ifndef MENU_H
#define MENU_H

#include "imagem.h"
#include "video.h"
#include "text.h"
#include "frontend.h"

class Menu : public FrontEnd
{
public:	
    Menu(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Menu();
	void update(Uint32);
	
	void draw(int x = 0, int y = 0);

private:
	Text *menu;
	Text *litio;
	Text *macauba;
	Text *entenda;
	Imagem *back;
	Imagem *earth;
	
	bool process_event(vector<SDL_Event>& events);
};

#endif
