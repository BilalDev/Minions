#include "Board.h"


Board::Board()
{}


Board::~Board()
{
	if (tileset)
		SDL_FreeSurface(tileset);
}


bool Board::init()
{
	XMLParser parser;

	if(parser.parseLevel("map/level1.xml") != NULL)
		return true;

	return false;
}


SDL_Surface* Board::getTileset()
{
	return this->tileset;
}


void Board::setTileset(std::string image)
{
	if (tileset)
		SDL_FreeSurface(tileset);

	tileset = IMG_Load(image.c_str());
}


Board::Tile const& Board::getTile()
{
	return tile;
}


void Board::setTile(Board::Tile const& tile)
{
	this->tile.h = tile.h;
	this->tile.w = tile.w;
}


Board::NbTiles const& Board::getNbTiles()
{
	return nbTiles;
}


void Board::setNbTiles(Board::NbTiles const& nbTiles)
{
	this->nbTiles.x = nbTiles.x;
	this->nbTiles.y = nbTiles.y;
}


Board::Scroll const& Board::getScroll()
{
	return scroll;
}


void Board::setScroll(Board::Scroll const& scroll)
{
	this->scroll.x = scroll.x;
	this->scroll.y = scroll.y;
}
void Board::setScroll(int x, int y)
{
	scroll.x = x;
	scroll.y = y;
}

Board::NbTilesWorld const& Board::getNbTilesWorld()
{
	return nbTilesWorld;
}


void Board::setNbTilesWorld(Board::NbTilesWorld const& nbTilesWorld)
{
	this->nbTilesWorld.x = nbTilesWorld.x;
	this->nbTilesWorld.y = nbTilesWorld.y;
}


std::list<Board::Block> &Board::getMap()
{
	return map;
}