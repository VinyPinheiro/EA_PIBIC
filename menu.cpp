#include "menu.h"

Menu::Menu(Video *video)
{
	menu = new Imagem(video, "imgs/menu.png");
	opcao1 = new Imagem(video, "imgs/menu.png");
	opcao2 = new Imagem(video, "imgs/menu.png");
	opcao3 = new Imagem(video, "imgs/menu.png");
	//entenda = new Entenda(video);
}

Menu::~Menu()
{
	delete menu;
	delete opcao1;
	delete opcao2;
	delete opcao3;
}

void
Menu::draw()
{
	menu->draw(250,100,0,0, 300,110);
	opcao1->draw(250,227,0,110,310,80);
	opcao2->draw(250,307,0,190,310,70);
	opcao3->draw(250,377,0,260,310,70);

}

bool
Menu::onMouseButtonEvent(SDL_MouseButtonEvent event)
{
	/*if(event.x >= 250 && event.x < 560 &&
		event.y >= 227 && event.y < 307)
	{
		cerr << "litio"<<endl;
	}
	else if(event.x >= 250 && event.x < 560 &&
		event.y >= 307 && event.y < 377)
	{
		cerr << "Macauba"<<endl;
	}
	else if(event.x >= 250 && event.x < 560 &&
		event.y >= 377 && event.y < 447)
	{
		cerr << "Entenda" << endl;
		entenda->draw();
	}
	* */
	return true;
}
