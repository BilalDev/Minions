#ifndef HERO_H
#define HERO_H

#include "Graphic.h"
#include "Board.h"
#include <cmath>

class Hero
{
public:
	Hero();
	~Hero();

	void	display(SDL_Surface *screen);
	bool	move(SDL_Rect destination);
	void	animate();

	Graphic &getGraphic();

private:
	Graphic graphic;
};

#endif /* !HERO_H */
