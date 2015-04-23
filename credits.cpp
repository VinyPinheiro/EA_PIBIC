#include "credits.h"
#include "imagem.h"
#include <SDL2/SDL_ttf.h>

Credits::Credits(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	const string font = "fontes/AjarSans-Regular.ttf";
	const int tam_integrantes = 45;
        
    alunos = new Text(v,font,60,"ALUNOS");
    alunos->setStyleItalic();
    alunos->setStyleBold();
    
    camila = new Text(v,font,tam_integrantes,"Camila Carneiro Ferrer");
    gesiel = new Text(v,font,tam_integrantes,"Gesiel dos Santos Freitas");
    vinicius = new Text(v,font,tam_integrantes,"Vinícius Pinheiro da Silva Corrêa");
    
    orientadores = new Text(v,font,60,"ORIENTADORES");
    orientadores->setStyleItalic();
    orientadores->setStyleBold();
    
    edson = new Text(v,font,tam_integrantes,"Edson Alves da Costa Junior");
    vitoria = new Text(v,font,tam_integrantes,"Maria Vitória Duarte Ferrari Tome");
}

Credits::~Credits()
{
	delete vitoria;
	delete edson;
	delete orientadores;
	delete vinicius;
	delete gesiel;
	delete camila;
    delete alunos;
}

void
Credits::draw(int, int)
{
	int xa = video->w()/2 - alunos->getW()/2;
	int xb = 15;
	
	alunos->draw(xa, xb);
	xb+=alunos->getH();
	
	xa = video->w()/2 - camila->getW()/2;
	camila->draw(xa, xb);
	xb+=camila->getH();
	
	xa = video->w()/2 - gesiel->getW()/2;
	gesiel->draw(xa, xb);
	xb+=gesiel->getH();
	
	xa = video->w()/2 - vinicius->getW()/2;
	vinicius->draw(xa, xb);
	xb+=vinicius->getH();
	
	xa = video->w()/2 - orientadores->getW()/2;
	xb+=15;	
	orientadores->draw(xa, xb);
	xb+=orientadores->getH();
	
	xa = video->w()/2 - edson->getW()/2;
	edson->draw(xa, xb);
	xb+=edson->getH();
	
	xa = video->w()/2 - vitoria->getW()/2;
	vitoria->draw(xa, xb);

}
