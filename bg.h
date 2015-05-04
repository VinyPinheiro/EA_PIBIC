#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "object.h"
#include "video.h"
#include "imagem.h"

#include <string>

using std::string;

class Bg : public Object
{
public:
    Bg(Video *video, const string& path);

private:
    Video *m_video;
    Imagem *m_img;

    void draw_self();
};

#endif
