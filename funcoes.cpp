#include "funcoes.h"

using namespace std;

void carrega_imagem(const char caminho[], SDL_Renderer *renderer, const int px, const int py, const double tx, const double ty)
{
	SDL_Surface* img;
	SDL_Rect destino;	
	SDL_RenderPresent(renderer);
	SDL_Texture *textura;
	img = IMG_Load(caminho);
	if(img == NULL)
		cerr << "Falha no carreamento da imagem" << endl;
	
	textura = SDL_CreateTextureFromSurface(renderer, img);
	if(textura == NULL)
		cerr << "Falha no carreamento da textura" << endl;
	
	destino.x = px;
	destino.y = py;
	destino.w = tx;
	destino.h = ty;
	
	SDL_FreeSurface(img);
	
	SDL_RenderCopy(renderer, textura, NULL, &destino);
	

}
