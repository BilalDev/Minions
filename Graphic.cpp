#include "Graphic.h"

Graphic::Graphic()
{}


Graphic::Graphic(std::string image, SDL_Rect position, SDL_Rect frame) : position (position), frame (frame)
{
	this->image = IMG_Load(image.c_str());
}


Graphic::~Graphic()
{}


SDL_Surface &Graphic::getImage()
{
	return *image;
}


SDL_Rect &Graphic::getFrame()
{
	return frame;
}


SDL_Rect &Graphic::getPosition()
{
	return position;
}
