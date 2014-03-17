#include "Board.h"


Board::Board()
{}


Board::~Board()
{
}


bool Board::init()
{
	return false;
}


int Board::getTileW()
{
	return this->tile_w;
}


int Board::getTIleH()
{
	return this->tile_h;
}


int Board::getNbTilesX()
{
	return this->nbTilesX;
}


SDL_Surface* Board::getTileset()
{
	return this->tileset;
}


std::vector<SDL_Rect, int>* Board::getProps()
{
	return this->props;
}


unsigned char** Board::getSchema()
{
	return this->schema;
}


int Board::getXScroll()
{
	return this->xScroll;
}


int Board::getYScroll()
{
	return this->yScroll;
}


int Board::getNbTilesWorldX()
{
	return this->nbTilesWorldX;
}


int Board::getNbTilesWorldY()
{
	return this->nbTilesWorldY;
}


int Board::getWindowW()
{
	return this->window_w;
}


int Board::getWindowH()
{
	return this->window_h;
}
