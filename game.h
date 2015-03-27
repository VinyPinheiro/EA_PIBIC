#ifndef GAME_H
#define GAME_H

#include "video.h"

class Game
{
public:
	Game();
	~Game();
	int run();
private:
	Video *video;
};

#endif
