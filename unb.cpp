#include "unb.h"

UnB::UnB(Video *v, Uint32 begin, Uint32 finish)
{
	video = v;
	unb = new Imagem(video, "imgs/UNB.png");
	fga = new Imagem(video, "imgs/FGA.jpg");
	end = finish + begin;
}

UnB::~UnB()
{
	delete unb;
	delete fga;
}
	
bool 
UnB::process_event(vector<SDL_Event>& events)
{
	return true;
}

void 
UnB::draw(int x1, int y1,int x2, int y2, Uint32 now)
{
	if (now < end)
	{
		unb->draw(x1, y1);
		fga->draw(x2, y2);
	}
}
void 
UnB::draw(int x, int y)
{
}
