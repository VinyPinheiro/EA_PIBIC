#ifndef RECT_H
#define RECT_H

#include "video.h"

class Rect
{

public:
	Rect(Video* v,int x,int y,int w, int h);
	~Rect();
	void draw();
	void setColor(int r, int g, int b, int a = 255);
	
	
private:
	Video *video;
	SDL_Rect* rect;
};

#endif
