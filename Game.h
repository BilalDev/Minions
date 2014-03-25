#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "EngineCore.h"
#include "Timer.h"

class Game
{
public:
	enum DIRECTION {
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
	Game();
	~Game();

	void display_board(SDL_Surface *screen);
	void move_board(int x, int y);

	Timer		getTimer();


private:
	Timer		timer;
};

#endif /* !GAME_H */