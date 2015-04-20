#ifndef ENTENDA_H
#define ENTENDA_H

#include "imagem.h"
#include "animation.h"
#include "video.h"
#include "frontend.h"

class Entenda : public FrontEnd
{
public:
	Entenda(Video *video, Level *next = 0, Uint32 duration = 3000);
	~Entenda();
	void update(Uint32);
	bool process_event(vector<SDL_Event>&);
	
	void draw(int x = 0, int y = 0);
	
private:
	Uint32 init;
	Imagem *balao;
	Imagem *aux;
	
	Animation *cenario;
	Animation *caminhao;
	Animation *mina;
};


#endif
