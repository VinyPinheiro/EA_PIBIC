#include "video.h"


Video::Video(int w, int h)
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
