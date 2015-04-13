#include "technologies.h"

Technologies::Technologies(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
    sdl = new Imagem(video, "imgs/SDL.png");
	cpp = new Imagem(video, "imgs/cpp.jpg");
	inkscape = new Imagem(video, "imgs/Inkscape.png");
}

Technologies::~Technologies()
{
	delete sdl;
	delete cpp;
	delete inkscape;
}
	
void 
Technologies::draw(int x1, int y1,int x2, int y2,int x3, int y3)
{
    sdl->draw(x1, y1);
    cpp->draw(x2, y2);
    inkscape->draw(x3, y3);
}
void 
Technologies::draw(int, int)
{
    draw(310, 50, 220,200, 316, 400);
}
