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
	void setColor(int r=255, int g=255, int b=255, int a = 255);
    
    int w() const;
    int h() const;

private:
    int m_w, m_h;
	SDL_Window* janela;
	SDL_Renderer *renderer;
};

#endif

