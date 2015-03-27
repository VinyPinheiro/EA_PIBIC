#include "earth.h"

Earth::Earth(Video *video)
{
    img = new Imagem(video, "imgs/earth.png");
    begin = 0;
    posx = posy = 0;
    paused = false;
    lastframe = 0;
}

Earth::~Earth()
{
    delete img;
}

void 
Earth::startAnimation(Uint32 now)
{
    begin = now;
}

void 
Earth::draw(Uint32 now)
{
    const Uint32 speed = 33*2;
    const int frames = 20;

    Uint32 elapsed = now - begin;

    int frame = elapsed / speed;

    //if (frame >= frames)
     //   frame = frames - 1;
    frame %= frames;

    if (paused)
        frame = lastframe;
    else
        lastframe = frame;

    int row = frame / 5;
    int column = frame % 5;

    int w = 192;
    int h = 192;

    int x = w * column;
    int y = h * row;

    img->draw(posx, posy, x, y, w, h);
}

bool 
Earth::onKeyboardEvent(SDL_KeyboardEvent event)
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
Earth::onMouseButtonEvent(SDL_MouseButtonEvent event)
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

