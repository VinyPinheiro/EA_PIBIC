#ifndef TEXT_H
#define TEXT_H

#include "imagem.h"
#include <SDL2/SDL_ttf.h>
#include "video.h"

class Text
{
public:
	Text(Video *video, const string& path, int size, const string& text,int r = 0,int g = 0,int b = 0,int a = 255);
	~Text();
	
	void draw(int x = 0, int y = 0);
	int getW() const;
	int getH() const;
	void setStyleNormal();
	void setStyleBold();
	void setStyleItalic();
	void setStyleUnderline();
private:
	Imagem *img;
	TTF_Font *font;
};

#endif
