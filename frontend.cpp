#include "frontend.h"
#include "video.h"

#include <iostream>

using namespace std;

FrontEnd::FrontEnd(Video *v, Level *n, Uint32 d)
    : video(v), next_level(n), duration(d), start(0), done_level(false)
{
}

bool 
FrontEnd::process_event(vector<SDL_Event>& events)
{
    for (auto event : events)
    {
        if (event.type == SDL_KEYDOWN or event.type == SDL_MOUSEBUTTONDOWN)
        {
            done_level = true;
            return true;
        }
    }

	return false;
}

void 
FrontEnd::update(Uint32 now)
{
    if (not start)
        start = now;

    if (now - start > duration)
        done_level = true;
}

bool 
FrontEnd::done() const
{
    return done_level;
}

Level * 
FrontEnd::next() const
{
    return next_level;
}
