#ifndef VIDEO_H
#define VIDEO_H

#include <SDL2/SDL.h>

class Video
{
public:
	Video(int w = 800, int h = 600);
	~Video();
	
	SDL_Renderer* getRenderer() const;
	void update();
	void erase();

    int w() const;
    int h() const;

private:
    int m_w, m_h;
	SDL_Window* janela;
	SDL_Renderer *renderer;
};

#endif

