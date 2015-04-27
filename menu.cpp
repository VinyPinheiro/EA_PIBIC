#include "menu.h"
#include "presentation.h"
#include "rect.h"
#include "entenda.h"

Menu::Menu(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	const string font = "fontes/AjarSans-Regular.ttf";
	const int font_size = 45;
	
	earth = new Imagem(video, "imgs/terra.png");
	back = new Imagem(video,"imgs/setaE.png");
	
    menu = new Text(v,font,font_size,"SIMULADOR AMBIENTAL",255,255,255);
    menu->setStyleItalic();
    menu->setStyleBold();
    
	litio = new Text(v,font,font_size,"Ciclo do Lítio",255,255,255);
	macauba = new Text(v,font,font_size,"Energia a partir da Macauba",255,255,255);
	entenda = new Text(v,font,font_size,"Entenda as produções",255,255,255);
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
	int xa, xirect = 104, widthrec = 592;
	Rect *aux;
	
	earth->draw(0,0,0,0,761,565,800,600);
	back->draw(15,15);
	
	xa = video->w()/2 - menu->getW()/2;
	aux = new Rect(video,xa-20,70,menu->getW()+40, menu->getH()+60);
	aux->setColor(0,0,0,200);
	aux->draw();
	free(aux);
	menu->draw(xa,100);
	
	xa = video->w()/2 - litio->getW()/2;
	aux = new Rect(video,xirect,227,widthrec, 80);
	aux->setColor(0,0,0,150);
	aux->draw();
	free(aux);
	litio->draw(xa,227);
	
	xa = video->w()/2 - macauba->getW()/2;
	aux = new Rect(video,xirect,317,widthrec, 80);
	aux->setColor(0,0,0, 150);
	aux->draw();
	free(aux);
	macauba->draw(xa,317);
	
	xa = video->w()/2 - entenda->getW()/2;
	aux = new Rect(video,xirect,407,widthrec, 80);
	aux->setColor(0,0,0, 150);
	aux->draw();
	free(aux);
	entenda->draw(xa,407);

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
			else if(event.button.x >= 104 && event.button.x < 592 &&
				event.button.y >= 227 && event.button.y < 307)
			{
				cerr << "litio"<<endl;
			}
			else if(event.button.x >= 104 && event.button.x < 592 &&
				event.button.y >= 317 && event.button.y < 387)
			{
				cerr << "Macauba"<<endl;
			}
			else if(event.button.x >= 104 && event.button.x < 592 &&
				event.button.y >= 407 && event.button.y < 467)
			{
				setNext(new Entenda(video));
				setDone(true);
			}
		}
    }

	return false;
}
