#include "game.h"
#include "imagem.h"
#include "animation.h"
#include "menu.h"
#include "unb.h"
#include "fomento.h"
#include "technologies.h"
#include "indicative_classification.h"
#include "presentation.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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

    rc = TTF_Init();

    if (rc != 0)
    {
        cerr << "Nao foi possivel inicializar a SDL_ttf: " << TTF_GetError()
            << endl;

        return;
    }

	video = new Video();
}

Game::~Game()
{
	delete video;
    TTF_Quit();
	SDL_Quit();
}

int Game::run()
{
	vector<SDL_Event> events;
    Uint32 now = SDL_GetTicks();
    
    Presentation *presentation = new Presentation(video);
    Indicative_classification *classification = new Indicative_classification(video,presentation);
	Technologies *technologies = new Technologies(video,classification);
    Fomento *fomento = new Fomento(video, technologies);
	UnB *unb = new UnB(video, fomento);
    Level *level = presentation;

	while(level and !quit)
	{
        now = SDL_GetTicks();
		events = get_events();
		events = process_event(events);
	    level->process_event(events);

        level->update(now);
		
		video->setColor(); // garantir o fundo branco
		video->erase();
        level->draw();
		video->update();
        
        

        if (level->getDone())
        {
            Level *next = level->getNext();
            delete level;
            level = next;
        }
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
