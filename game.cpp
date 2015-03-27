#include "game.h"
#include "imagem.h"
#include "earth.h"

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

    Earth *earth = new Earth(video);

	Imagem *globo = new Imagem(video,"imgs/globo.jpg");
	globo->draw(0,0);
    Imagem *litio = new Imagem(video,"imgs/Litio.png");
	litio->draw(10,40);
	Imagem *simuladores = new Imagem(video,"imgs/Simuladores.png");

    Uint32 now = SDL_GetTicks();
    earth->startAnimation(now);

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
				if(e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				} else
                    earth->onKeyboardEvent(e.key);
			}
			
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
			/*	if(e.button.x >= 10 && e.button.x < 10+litio->getW() &&
					e.button.y >= 40 && e.button.y < 40+litio->getH())
					
				{
					simuladores->draw(100,200);
				} */
                    earth->onMouseButtonEvent(e.button);
			}
		}

		video->erase();
        earth->draw(now);
		video->update();
		SDL_Delay(1);
	}
	
	delete globo;
	delete litio;
	return 0;
}

