#include "credits.h"
#include "imagem.h"
#include <SDL2/SDL_ttf.h>

Credits::Credits(Video *v, Level *n, Uint32 d)
    : FrontEnd(v, n, d)
{
    TTF_Font *m_font = TTF_OpenFont("AjarSans-Regular.ttf", 60);
    TTF_SetFontStyle(m_font, TTF_STYLE_BOLD);

    TTF_Font *m_font2 = TTF_OpenFont("AjarSans-Regular.ttf", 30);

    SDL_Color m_color;
    m_color.r = m_color.g = m_color.b = 0;
    m_color.a = 255;

    SDL_Surface *s = TTF_RenderText_Blended(m_font, "ALUNOS", m_color);
    SDL_Texture *textura = SDL_CreateTextureFromSurface(v->getRenderer(), s);
    m_alunos = new Imagem(v, textura, s->w, s->h);
    SDL_FreeSurface(s);

    s = TTF_RenderText_Blended(m_font2, "Vinicius Pinheiro da Silva Correa", m_color);
    textura = SDL_CreateTextureFromSurface(v->getRenderer(), s);
    m_vinicius = new Imagem(v, textura, s->w, s->h);
    SDL_FreeSurface(s);


    TTF_CloseFont(m_font);
    TTF_CloseFont(m_font2);
//	credits = new Imagem(video, "imgs/creditos.png");
}

Credits::~Credits()
{
    delete m_vinicius;
    delete m_alunos;
}

void
Credits::draw(int x, int y)
{
    int xa = video->w()/2 - m_alunos->getW()/2;
    m_alunos->draw(xa, 25);

    xa = video->w()/2 - m_vinicius->getW()/2;
    m_vinicius->draw(xa, 120);
}
