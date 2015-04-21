#include "imagem.h"
#include <SDL2/SDL_ttf.h>
#include "text.h"

Text::Text(Video *video, const string& path, int size, const string& text,int r,int g,int b,int a)
{
	//Define font type
	font = TTF_OpenFont(path.c_str(), size);
	
	//Define color font
	SDL_Color color;
    color.r = r;
	color.g = g;
	color.b = b;
    color.a = a;
    
    //Create Surface
    SDL_Surface *s = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture *textura = SDL_CreateTextureFromSurface(video->getRenderer(), s);
    img = new Imagem(video, textura, s->w, s->h);
    SDL_FreeSurface(s);
    
    //Close fonte
    TTF_CloseFont(font);
}

Text::~Text()
{
	delete img;
}

void
Text::draw(int x, int y)
{
	img->draw(x, y);
}

int
Text::getW() const
{
	return img->getW();
}

int
Text::getH() const
{
	return img->getH();
}

void 
Text::setStyleNormal()
{
	TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
}

void 
Text::setStyleBold()
{
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
}

void 
Text::setStyleItalic()
{
	TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
}

void 
Text::setStyleUnderline()
{
	TTF_SetFontStyle(font, TTF_STYLE_UNDERLINE);
}
