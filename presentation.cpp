#include "presentation.h"
#include "credits.h"
#include "menu.h"
#include "rect.h"

Presentation::Presentation(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	const string font = "fontes/AjarSans-Regular.ttf";
	const int font_size = 45;
	
	earth = new Imagem(video, "imgs/terra.png");
    menu = new Text(v,font,font_size,"SIMULADOR AMBIENTAL",255,255,255);
    menu->setStyleItalic();
    menu->setStyleBold();
	start = new Text(v,font,font_size,"INICIAR",255,255,255);
	option = new Text(v,font,font_size,"CRÉDITOS",255,255,255);
	exit = new Text(v,font,font_size,"SAIR",255,255,255);
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
Presentation::update(Uint32){}

void 
Presentation::draw(int, int)
{
	
	Rect *aux;
	
	earth->draw(0,0,0,0,761,565,800,600);
	
	int xa = video->w()/2 - menu->getW()/2;
	aux = new Rect(video,xa-20,100,menu->getW()+40, menu->getH()+60);
	aux->setColor(0,0,0,200);
	aux->draw();
	free(aux);
	menu->draw(xa,130);
	
	xa = video->w()/2 - start->getW()/2;
	aux = new Rect(video,250,227,310, 80);
	aux->setColor(0,0,0,150);
	aux->draw();
	free(aux);
	start->draw(xa,227);
	
	xa = video->w()/2 - option->getW()/2;
	aux = new Rect(video,250,307,310, 80);
	aux->setColor(0,0,0, 150);
	aux->draw();
	free(aux);
	option->draw(xa,307);
	
	xa = video->w()/2 - exit->getW()/2;
	aux = new Rect(video,250,387,310, 80);
	aux->setColor(0,0,0, 150);
	aux->draw();
	free(aux);
	exit->draw(xa,377);
	
}

bool 
Presentation::process_event(vector<SDL_Event>& events)
{
    for (auto event : events)
    {
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 227 && event.button.y < 307)
			{
				setNext(new Menu(video));
				setDone(true);
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 307 && event.button.y < 387)
			{
				setNext(new Credits(video,new Presentation(video),5000));
				setDone(true);
			}
			else if(event.button.x >= 250 && event.button.x < 560 &&
				event.button.y >= 387 && event.button.y < 447)
			{
				setNext(nullptr);
				setDone(true);
			}
            return true;
        }
    }

	return false;
}

