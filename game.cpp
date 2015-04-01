#include "game.h"
#include "imagem.h"
#include "animation.h"
#include "menu.h"
#include "unb.h"
#include "fomento.h"
#include "technologies.h"
#include "indicative_classification.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

Game::Game()
{
	quit = false;
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
	vector<SDL_Event> events;
    Uint32 now = SDL_GetTicks(), start = SDL_GetTicks();
    
    Indicative_classification classification(video, start + 9000, 3000);
	Technologies technologies(video,start + 6000, 3000);
    Fomento fomento(video, start + 3000, 3000);
	UnB unb(video,start, 3000);

	while(!quit)
	{
        now = SDL_GetTicks();
		events = get_events();
		events = process_event(events);
		unb.process_event(events);
		
	
		video->erase();
        
        unb.draw(223, 100, 136,300, now);
        
        fomento.draw(38,175,now);
        
        technologies.draw(310, 50, 220,200, 316, 400, now);
        
        classification.draw(0,400,now);
        
		video->update();
	}
	
	return 0;
}

vector<SDL_Event> Game::get_events() const
{
	vector<SDL_Event> events;
	SDL_Event e;
	
	while( SDL_PollEvent( &e ) != 0 )
		events.push_back(e);
	return events;
}

vector<SDL_Event> Game::process_event(vector<SDL_Event>& events)
{
	vector<SDL_Event> np;
	
	for(auto e : events)
	{
		if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
			quit = true;
		else
			np.push_back(e);
	}
	
	return np;
}
