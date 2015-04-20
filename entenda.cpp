#include "entenda.h"

Entenda::Entenda(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	mina = new Animation(video,"entenda/mina.png");
	cenario = new Animation(video,"entenda/escavacao.png");
	balao = new Imagem(video,"entenda/balao.png");
	
	mina->startAnimation(d);
	mina->setPos(15,300);
	
}

Entenda::~Entenda()
{
	delete balao;
	delete cenario;
	delete mina;
}

void
Entenda::update(Uint32 now)
{
	init = now;
}

void 
Entenda::draw(int, int)
{
	cenario->draw(init,1,1,600,113,true);
	mina->draw(init,2,2,100,270,true);
	balao->draw(100,180);
}
bool 
Entenda::process_event(vector<SDL_Event>&)
{
	return true;
}
