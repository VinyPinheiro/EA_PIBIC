#include "menu.h"
#include "presentation.h"
#include "entenda.h"

Menu::Menu(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	earth = new Imagem(video, "imgs/terra.png");
	back = new Imagem(video,"imgs/setaE.png");
	menu = new Imagem(video, "imgs/menu.png");
	litio = new Imagem(video, "imgs/menu.png");
	macauba = new Imagem(video, "imgs/menu.png");
	entenda = new Imagem(video, "imgs/menu.png");
}

Menu::~Menu()
{
	delete entenda;
	delete macauba;
	delete litio;
	delete menu;
	delete back;
	delete earth;
}

void
Menu::draw(int,int)
{
	earth->draw(0,0,0,0,761,565,800,600);
	back->draw(15,15);
	menu->draw(250,100,0,0, 300,110);
	litio->draw(250,227,0,110,310,80);
	macauba->draw(250,307,0,190,310,70);
	entenda->draw(250,377,0,260,310,70);

}


void
Menu::update(Uint32){}

bool 
Menu::process_event(vector<SDL_Event>& events)
{
    for (auto event : events)
    {
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.x >= 15 && event.button.x < 65 &&
				event.button.y >= 15 && event.button.y < 87)
			{
				setNext(new Presentation(video));
				setDone(true);
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 227 && event.button.y < 307)
			{
				cerr << "litio"<<endl;
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 307 && event.button.y < 377)
			{
				cerr << "Macauba"<<endl;
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 377 && event.button.y < 447)
			{
				setNext(new Entenda(video));
				setDone(true);
			}
		}
    }

	return false;
}
