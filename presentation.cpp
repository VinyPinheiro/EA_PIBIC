#include "presentation.h"
#include "credits.h"

Presentation::Presentation(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	earth = new Imagem(video, "imgs/terra.png");
    menu = new Imagem(video, "imgs/apresentacao.png");
	start = new Imagem(video, "imgs/apresentacao.png");
	option = new Imagem(video, "imgs/apresentacao.png");
	exit = new Imagem(video, "imgs/apresentacao.png");
}

Presentation::~Presentation()
{
	delete exit;
	delete option;
	delete start;
	delete menu;
	delete earth;
}

void 
Presentation::draw(int, int)
{
	earth->draw(0,0,0,0,761,565,800,600);
	menu->draw(250,100,0,0, 300,110);
	start->draw(250,227,0,110,310,80);
	option->draw(250,307,0,190,310,70);
	exit->draw(250,377,0,260,310,70);
}

void 
Presentation::update(Uint32)
{}

bool 
Presentation::process_event(vector<SDL_Event>& events)
{
    for (auto event : events)
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
			if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 307 && event.button.y < 377)
			{
				Credits *credits = new Credits(video,new Presentation(video),3000);
				setNext(credits);
				setDone(true);
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 377 && event.button.y < 447)
			{
				setNext(NULL);
				setDone(true);
			}
            return true;
        }
    }

	return false;
}
