#ifndef SIMULATION_H
#define SIMULATION_H

#include "level.h"
#include "video.h"
#include "object.h"

class Simulation : public Level
{
public: 
    Simulation(Video *video);
    ~Simulation();

	bool process_event(vector<SDL_Event>& events);	
	void draw(int x = 0, int y = 0);
    void update(Uint32 now);
    void setDone(bool done);
    void setNext(Level * n);

    bool getDone() const;
    Level * getNext() const;

private:
    vector<Object *> m_objs;
    Video *m_video;
    bool m_done;
};

#endif
