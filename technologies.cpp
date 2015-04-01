#include "technologies.h"

Technologies::Technologies(Video *v, Uint32 begin, Uint32 finish)
{
	video = v;
	sdl = new Imagem(video, "imgs/SDL.png");
	cpp = new Imagem(video, "imgs/cpp.jpg");
	inkscape = new Imagem(video, "imgs/Inkscape.png");
	end = finish + begin;
	start = begin;
}

Technologies::~Technologies()
{
	delete sdl;
	delete cpp;
	delete inkscape;
}
	
bool 
Technologies::process_event(vector<SDL_Event>& events)
{
	return true;
}

void 
Technologies::draw(int x1, int y1,int x2, int y2,int x3, int y3, Uint32 now)
{
	if (now < end && now > start)
	{
		sdl->draw(x1, y1);
		cpp->draw(x2, y2);
		inkscape->draw(x3, y3);
	}
}
void 
Technologies::draw(int x, int y)
{
}
