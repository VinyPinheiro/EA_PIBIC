#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>

#include "video.h"

using std::vector;


class Game
{
public:
	Game();
	~Game();
	int run();
private:
	bool quit;
	Video *video;
	
	vector<SDL_Event> get_events() const;
	vector<SDL_Event> process_event(vector<SDL_Event>& events);
};

#endif
