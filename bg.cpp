#include "bg.h"

Bg::Bg(Video *video, const string& path)
    : Object(path, 0, 0), m_video(video)
{
    m_img = new Imagem(video, path);
}

void
Bg::draw_self()
{
    if (m_img)
        m_img->draw(m_x, m_y);
}
