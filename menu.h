#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include "video.h"
#include "imagem.h"

class Menu
{
public:
	Menu(Video *video);
	~Menu();
	
	void draw();	
    bool onMouseButtonEvent(SDL_MouseButtonEvent event);
private:
	Imagem *menu;
	Imagem *opcao1;
	Imagem *opcao2;
	Imagem *opcao3;
};

#endif
