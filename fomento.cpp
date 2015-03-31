#include "fomento.h"

Fomento::Fomento(Video *v, Uint32 begin, Uint32 finish)
{
	video = v;
	fomento = new Imagem(video, "imgs/cnpq_capes.jpg");
	end = finish + begin;
	start = begin;
}

Fomento::~Fomento()
{
	delete fomento;
}
	
bool 
Fomento::process_event(vector<SDL_Event>& events)
{
	return true;
}

void 
Fomento::draw(int x, int y, Uint32 now)
{
	if (now < end && now > start)
		fomento->draw(x, y);
}
void 
Fomento::draw(int x, int y)
{
}
