#ifndef EARTH_H
#define EARTH_H

#include <SDL2/SDL.h>
#include "video.h"
#include "imagem.h"

class Earth {
public:
    Earth(Video *video);
    ~Earth();

    void startAnimation(Uint32 now);
    void draw(Uint32 now);

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

