#include "indicative_classification.h"

Indicative_classification::Indicative_classification(Video *v, Uint32 begin, Uint32 finish)
{
	video = v;
	classification = new Imagem(video, "imgs/indicative_classification.png");
	end = finish + begin;
	start = begin;
}

Indicative_classification::~Indicative_classification()
{
	delete classification;
}
	
bool 
Indicative_classification::process_event(vector<SDL_Event>& events)
{
	return true;
}

void 
Indicative_classification::draw(int x, int y, Uint32 now)
{
	if (now < end && now > start)
		classification->draw(x, y);
}
void 
Indicative_classification::draw(int x, int y)
{
}
