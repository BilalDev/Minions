#include "Hero.h"


Hero::Hero()
{
	SDL_Rect position;
	SDL_Rect frame;
	position.x = 0;
	position.y = 0;
	frame.x = 0;
	frame.y = 0;
	this->graphic = Graphic("resources/captain_america_walking.png", position, frame);
	this->graphic.getFrame().w = this->graphic.getImage().w / 10;
	this->graphic.getFrame().h = this->graphic.getImage().h;
}


Hero::~Hero()
{
}


void Hero::display(SDL_Surface *screen)
{
	SDL_BlitSurface(&graphic.getImage(), &graphic.getFrame(), screen, &graphic.getPosition());
}


bool Hero::move(SDL_Rect destination)
{
	float OB, AB, rada = 0.0f;
	int y2 = destination.y, y1 = graphic.getPosition().y;
	int x2 = destination.x, x1 = graphic.getPosition().x;

	// Same position => don't move
	if (x2 == x1 && y2 == y1)
		return false;

	OB = abs(x2 - x1);
	AB = abs(y1 - y2);
	rada = tan(AB / OB);

	// Player goes to the RIGHT
	if (x2 > x1)
	{
		graphic.getPosition().x += (10 * cos(rada));

		// UP
		if (y2 < y1)
			graphic.getPosition().y -= (10 * sin(rada));
		// DOWN
		else
			graphic.getPosition().y += (10 * sin(rada));

		if (x1 >= x2)
		{
			graphic.getPosition().x = x2;
			graphic.getPosition().y = y2;
			return false;
		}

		return true;
	}

	// Player goes to the LEFT
	else if (x2 < x1)
	{
		graphic.getPosition().x -= (10 * cos(rada));

		// UP
		if (y2 < y1)
			graphic.getPosition().y -= (10 * sin(rada));
		// DOWN
		else
			graphic.getPosition().y += (10 * sin(rada));

		if (x1 <= x2)
		{
			graphic.getPosition().x = x2;
			graphic.getPosition().y = y2;
			return false;
		}

		return true;
	}
	else
		return false;
}


void Hero::animate()
{

}



Graphic& Hero::getGraphic()
{
	return graphic;
}
