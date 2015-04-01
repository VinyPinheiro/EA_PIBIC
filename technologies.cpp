#include "technologies.h"

Technologies::Technologies(Video *v, Uint32 begin, Uint32 finish)
{
	video = v;
	unb = new Imagem(video, "imgs/SDL.png");
	fga = new Imagem(video, "imgs/cpp.jpg");
	end = finish + begin;
	start = begin;
}

Technologies::~Technologies()
{
	delete unb;
	delete fga;
}
	
bool 
Technologies::process_event(vector<SDL_Event>& events)
{
	return true;
}

void 
Technologies::draw(int x1, int y1,int x2, int y2, Uint32 now)
{
	if (now < end && now > start)
	{
		unb->draw(x1, y1);
		fga->draw(x2, y2);
	}
}
void 
Technologies::draw(int x, int y)
{
}
