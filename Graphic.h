#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "headers.h"

class Graphic
{
public:
	Graphic();
	Graphic(std::string image, SDL_Rect position, SDL_Rect frame);
	~Graphic();

	SDL_Surface &getImage();
	SDL_Rect	&getFrame();
	SDL_Rect	&getPosition();


private:
	SDL_Surface *image;
	SDL_Rect	frame;
	SDL_Rect	position;
};

#endif /* !GRAPHIC_H */