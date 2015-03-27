#include "game.h"
#include "imagem.h"
#include "animation.h"
#include "menu.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

Game::Game()
{
	int rc = SDL_Init(SDL_INIT_VIDEO);
	if(rc != 0)
	{
		cerr << "Nao foi possivel inicializar a SDL: " << SDL_GetError()
			<< endl;
		return;
	}
	video = new Video();
}

Game::~Game()
{
	delete video;
	SDL_Quit();
}

int Game::run()
{
	bool quit = false;
	SDL_Event e;

    Animation *earth = new Animation(video,"imgs/earth.png");
    Uint32 now = SDL_GetTicks(), start = SDL_GetTicks();
    earth->startAnimation(now);
	Menu *menu = new Menu(video);
	Imagem *terra = new Imagem(video, "imgs/terra.png");
	while(!quit)
	{
        now = SDL_GetTicks();
    
		while( SDL_PollEvent( &e ) != 0 )
		{
			if(e.type == SDL_QUIT )
			{
				quit = true;
			}
			
			if(e.type == SDL_KEYDOWN)
			{
				earth->onKeyboardEvent(e.key);
			}
			
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				if(now >= start + 33*2*20 || !earth->getState())
				{
					menu->onMouseButtonEvent(e.button);
				}
                    earth->onMouseButtonEvent(e.button);
			}
		}
		video->erase();
        //earth->draw(now,20,5,192,192,true);
        
		terra->draw(0,0,0,0,761,565,800,600);
		if(now >= start + 33*2*20 || !earth->getState())
		{
			menu->draw();
		}
		video->update();
	}
	
	return 0;
}

