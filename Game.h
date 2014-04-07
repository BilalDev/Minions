#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "EngineCore.h"
#include "Timer.h"
#include "Hero.h"

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

	Timer				&getTimer();
	std::vector<Hero>	&getHeroes();


private:
	Timer				timer;
	std::vector<Hero>	heroes;
};

#endif /* !GAME_H */
