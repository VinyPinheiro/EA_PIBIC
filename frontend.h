#ifndef FRONT_END_H
#define FRONT_END_H

#include "level.h"

class Video;

class FrontEnd : public Level {
public:
    FrontEnd(Video *video, Level *next = 0, Uint32 duration = 3000);

	virtual bool process_event(vector<SDL_Event>& events);
    virtual void update(Uint32 now);
    virtual void setDone(bool done);
    virtual void setNext(Level * n);

    virtual bool getDone() const;
    virtual Level * getNext() const;

protected:
	Video *video;
    Level *next_level;
	Uint32 duration, start;
    bool done_level;
};

#endif

