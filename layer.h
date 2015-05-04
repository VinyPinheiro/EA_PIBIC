#ifndef LAYER_H
#define LAYER_H

#include "object.h"
#include "video.h"
#include "color.h"

class Layer : public Object
{
public:
    Layer(Video *v, int x, int y, int w = 1200, int h = 260, 
        const Color& background = Color::WHITE);
    ~Layer() {}

    int w() const;
    int h() const;

private:
    Video *m_video;
    int m_w, m_h;
    Color m_bg;

    void update_self(unsigned long elapsed);
    void draw_self();
};

#endif
