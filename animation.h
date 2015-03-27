#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>
#include "video.h"
#include "imagem.h"

class Animation {
public:
    Animation(Video *video,const string caminho);
    ~Animation();

    void startAnimation(Uint32 now);
	void draw(Uint32 now, const int frames, const int rows, const int w, const int h);

    bool onKeyboardEvent(SDL_KeyboardEvent event);
    bool onMouseButtonEvent(SDL_MouseButtonEvent event);

private:
    Imagem *img;
    Uint32 begin;
    int posx, posy;
    bool paused;
    int lastframe;
};


#endif

