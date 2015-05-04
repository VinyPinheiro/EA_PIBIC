#include "layer.h"
#include "video.h"

#include <SDL2/SDL.h>

Layer::Layer(Video *v, int x, int y, int w, int h, const Color& background)
    : Object("", x, y), m_video(v), m_w(w), m_h(h), m_bg(background)
{
}

int
Layer::w() const
{
    return m_w;
}

int
Layer::h() const
{
    return m_h;
}

void
Layer::update_self(unsigned long)
{
}

void
Layer::draw_self()
{
    SDL_Rect rect { m_x, m_y, m_w, m_h };
    SDL_SetRenderDrawColor(m_video->getRenderer(), m_bg.r(), m_bg.g(), 
        m_bg.b(), m_bg.a());

    SDL_RenderFillRect(m_video->getRenderer(), &rect); 
}
