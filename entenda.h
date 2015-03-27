#ifndef ENTENDA_H
#define ENTENDA_H

#include <SDL2/SDL.h>
#include "video.h"
#include "imagem.h"

class Entenda
{
public:
	Entenda(Video *video);
	~Entenda();
	bool Altera_imagem(string caminho, Imagem img,int x, int y, int x_orig, int y_orig, int w_orig, int h_orig);
	
	void draw();	
private:
	Imagem *fundo;
};

#endif
