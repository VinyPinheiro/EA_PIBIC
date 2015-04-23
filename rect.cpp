#include "rect.h"
#include "video.h"
#include "imagem.h"

Rect::Rect(Video* v,int x,int y,int w, int h)
{
	rect = new SDL_Rect();
	//*rect= {x,y,w,h};
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	video = v;
}

Rect::~Rect()
{
	delete rect;
}

void 
Rect::setColor(int r, int g, int b, int a)
{
	video->setColor(r,g,b,a);
}

void
Rect::draw()
{
	SDL_RenderFillRect(video->getRenderer(), rect);
}
