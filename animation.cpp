#include "animation.h"
#include <string>

Animation::Animation(Video *video,const string caminho)
{
    img = new Imagem(video, caminho);
    begin = 0;
    posx = posy = 0;
    paused = false;
    lastframe = 0;
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
Animation::draw(Uint32 now, const int frames, const int rows, const int w, const int h)
{
    const Uint32 speed = 33*2;

    Uint32 elapsed = now - begin;

    int frame = elapsed / speed;

    //if (frame >= frames)
     //   frame = frames - 1;
    frame %= frames;

    int row = frame / rows;
    int column = frame % rows;
    
    int x = w * column;
    int y = h * row;

    img->draw(posx, posy, x, y, w, h);
}

bool 
Animation::onKeyboardEvent(SDL_KeyboardEvent event)
{
    int speed = 5;

    switch (event.keysym.sym) {
    case SDLK_UP:
        posy -= speed;
        return true;
    case SDLK_DOWN:
        posy += speed;
        return true;
    case SDLK_LEFT:
        posx -= speed;
        return true;
    case SDLK_RIGHT:
        posx += speed;
        return true;
    }

    return false;
}

bool 
Animation::onMouseButtonEvent(SDL_MouseButtonEvent event)
{
    if (event.button ==  SDL_BUTTON_RIGHT)
    {
        paused = true;
        return true;
    } else if (event.button == SDL_BUTTON_LEFT)
    {
        paused = false;
        return true;
    }

    return false;
}

