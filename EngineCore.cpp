#include "EngineCore.h"

EngineCore::EngineCore()
{
}


EngineCore::~EngineCore()
{
}


bool EngineCore::init()
{
	SDL_Rect **modes;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur lors du chargement de la SDL %s", SDL_GetError());
		return false;
	}

	modes = SDL_ListModes(NULL, SDL_FULLSCREEN | SDL_HWSURFACE);

	if (modes == (SDL_Rect**)0)
	{
		fprintf(stderr, "Aucun mode n'est possible %s", SDL_GetError());
		return false;
	}

	screen_height = modes[0]->h;
	screen_width = modes[0]->w;

	if (!Singleton<Board>::getInstance().init())
		return false;

	return true;
}


int EngineCore::getHeight()
{
	return screen_height;
}


int EngineCore::getWidth()
{
	return screen_width;
}
