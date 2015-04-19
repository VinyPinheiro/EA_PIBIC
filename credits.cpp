#include "credits.h"

Credits::Credits(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
	credits = new Imagem(video, "imgs/creditos.png");
}

Credits::~Credits()
{
	delete credits;
}

void
Credits::draw(int x, int y)
{
	credits->draw(x, y);
}
void
Credits::draw(int, int)
{
    draw(0, 0);
}
