#include "unb.h"

UnB::UnB(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	unb = new Imagem(video, "imgs/UNB.png");
	fga = new Imagem(video, "imgs/FGA.jpg");
}

UnB::~UnB()
{
	delete fga;
	delete unb;
}
	
void 
UnB::draw(int x1, int y1,int x2, int y2)
{
    unb->draw(x1, y1);
    fga->draw(x2, y2);
}

void 
UnB::draw(int, int)
{
    draw(223, 100, 136, 300);
}

