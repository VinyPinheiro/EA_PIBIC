#include "animation.h"

Animation::Animation(Video *video,const string caminho)
{
    img = new Imagem(video, caminho);
    begin = 0;
    posx = posy = 0;
    paused = false;
    lastframe = 0;
    state = true;
}

Animation::~Animation()
{
    delete img;
}

void 
Animation::startAnimation(Uint32 now)
{
    begin = now;
}

void 
Animation::draw(Uint32 now, const int frames, const int rows, const int w, const int h, const bool loop)
{
	if(!state)
		return;
    const Uint32 speed = 33*2*2;

    Uint32 elapsed = now - begin;

    int frame = elapsed / speed;
	if(loop)
    {
		frame %= frames;
    }
    else
	{
		if (frame >= frames)
			frame = frames - 1;
	}

    int row = frame / rows;
    int column = frame % rows;
    
    int x = w * column;
    int y = h * row;

    img->draw(posx, posy, x, y, w, h);
}

void
Animation::setPos(int x, int y)
{
	posx = x;
	posy = y;
}

bool
Animation::getState()
{
	return state;
}
