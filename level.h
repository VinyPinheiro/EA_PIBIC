#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SDL2/SDL.h>

using std::vector;

class Level
{
public: 
	virtual bool process_event(vector<SDL_Event>& events) = 0;	
	virtual void draw(int x, int y) = 0;

};



#endif
