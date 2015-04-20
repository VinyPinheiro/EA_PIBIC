#include "video.h"


Video::Video(int w, int h)
    : m_w(w), m_h(h)
{
	SDL_CreateWindowAndRenderer(w, h, 0, &janela, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

Video::~Video()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(janela);
}

SDL_Renderer* Video::getRenderer() const
{
	return renderer;
}

void Video::update()
{
	SDL_RenderPresent(renderer);
}

void Video::erase()
{
	SDL_RenderClear(renderer);
}

int
Video::w() const
{
    return m_w;
}

int
Video::h() const
{
    return m_h;
}

