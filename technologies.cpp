#include "technologies.h"

Technologies::Technologies(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
    sdl = new Imagem(video, "imgs/SDL.png");
	inkscape = new Imagem(video, "imgs/Inkscape.png");
}

Technologies::~Technologies()
{
	delete sdl;
	delete inkscape;
}
	
void 
Technologies::draw(int x1, int y1,int x2, int y2)
{
    sdl->draw(x1, y1);
    inkscape->draw(x2, y2);
}
void 
Technologies::draw(int, int)
{
	
    //draw(310, 50, 220,200, 316, 400);
    draw(310, 100, 316, 250);
}
