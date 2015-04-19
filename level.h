#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SDL2/SDL.h>

using std::vector;

class Level
{
public: 
    virtual ~Level() {}

	virtual bool process_event(vector<SDL_Event>& events) = 0;	
	virtual void draw(int x = 0, int y = 0) = 0;
    virtual void update(Uint32 now) = 0;
    virtual void setDone(bool done) = 0;
    virtual void setNext(Level * n) = 0;

    virtual bool getDone() const = 0;
    virtual Level * getNext() const = 0;
};

#endif
