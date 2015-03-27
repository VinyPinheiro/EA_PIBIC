#ifndef IMAGEM_H
#define IMAGEM_H

#include "video.h"
#include <iostream>
#include <string>

using namespace std;

class Imagem
{
public:
	Imagem(Video* video, const string& path);
	~Imagem();
	
	void draw(int x, int y);
	void draw(int x, int y, int x_orig, int y_orig, int w_orig, int h_orig);
	void draw(int x, int y, int x_orig, int y_orig, int w_orig, int h_orig,int w_dest, int h_dest);
	int getW() const;
	int getH() const;
private:
	Video *video;
	SDL_Texture *textura;
	int w,h;
    int posx, posy;
};

#endif

