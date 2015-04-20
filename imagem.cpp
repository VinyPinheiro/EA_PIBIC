#include "imagem.h"
#include <SDL2/SDL_image.h>

Imagem::Imagem(Video* video, const string& path)
{
	this->video = video;
	
	SDL_Surface* img = IMG_Load(path.c_str());
	if(img == NULL)
		cerr << "Falha no carreamento da imagem" << endl;
		
	w = img->w;
	h = img->h;
	textura = SDL_CreateTextureFromSurface(video->getRenderer(), img);
	if(textura == NULL)
		cerr << "Falha no carreamento da textura" << endl;
	
	SDL_FreeSurface(img);
}

Imagem::Imagem(Video* video, SDL_Texture *texture, int w, int h)
{
    textura = texture;
    this->w = w;
    this->h = h;
    this->video = video;
}

Imagem::~Imagem()
{
	SDL_DestroyTexture(textura);
}

void Imagem::draw(int x, int y)
{
	SDL_Rect destino;	
	destino.x = x;
	destino.y = y;
	destino.w = w;
	destino.h = h;
	
	SDL_RenderCopy(video->getRenderer(), textura, NULL, &destino);
}

void 
Imagem::draw(int x, int y, int x_orig, int y_orig, int w_orig, int h_orig)
{	
    SDL_Rect destino;	
	destino.x = x;
	destino.y = y;
	destino.w = w_orig;
	destino.h = h_orig;
	
    SDL_Rect origem;
    origem.x = x_orig;
    origem.y = y_orig;
    origem.w = w_orig;
    origem.h = h_orig;

	SDL_RenderCopy(video->getRenderer(), textura, &origem, &destino);
}
void 
Imagem::draw(int x, int y, int x_orig, int y_orig, int w_orig, int h_orig,int w_dest, int h_dest)
{	
    SDL_Rect destino;	
	destino.x = x;
	destino.y = y;
	destino.w = w_dest;
	destino.h = h_dest;
	
    SDL_Rect origem;
    origem.x = x_orig;
    origem.y = y_orig;
    origem.w = w_orig;
    origem.h = h_orig;

	SDL_RenderCopy(video->getRenderer(), textura, &origem, &destino);
}

int Imagem::getW() const
{
	return w;
}

int Imagem::getH() const
{
	return h;
}
