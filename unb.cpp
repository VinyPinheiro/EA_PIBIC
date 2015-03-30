#include "unb.h"

UnB::UnB(Video *v)
{
	video = v;
	unb = new Imagem(video, "imgs/UNB.png");
	visible = false;
}

UnB::~UnB()
{
	delete unb;
}
	
bool 
UnB::process_event(vector<SDL_Event>& events)
{
	for(auto e : events)
	{
		if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_u)
			visible = !visible;
	}
	
	return true;
}

void 
UnB::draw(int x, int y)
{
	if (visible)
		unb->draw(x, y);
}
