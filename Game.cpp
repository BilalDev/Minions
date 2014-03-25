#include "Game.h"


Game::Game()
{
	timer.start();
}


Game::~Game()
{
}


void Game::display_board(SDL_Surface *screen)
{
	SDL_Rect dest;
	int minx, maxx, miny, maxy;
	Board& board = Singleton<Board>::getInstance();
	EngineCore& engine = Singleton<EngineCore>::getInstance();
	
	minx = board.getScroll().x / board.getTile().w;
	miny = board.getScroll().y / board.getTile().h;
	maxx = (board.getScroll().x + engine.getWidth()) / board.getTile().w;
	maxy = (board.getScroll().y + engine.getHeight()) / board.getTile().h;

	std::list<Board::Block>::iterator it = board.getMap().begin();
	while (it != board.getMap().end())
	{
		if (it->x >= minx && it->x <= maxx
			&& it->y >= miny && it->y <= maxy)
		{
			dest.x = it->x * board.getTile().w - board.getScroll().x;
			dest.y = it->y * board.getTile().h - board.getScroll().y;

			SDL_BlitSurface(board.getTileset(), &(it->texture), screen, &dest);
		}
		it++;
	}
}


void Game::move_board(int x, int y)
{
	int xscroll, yscroll, wtile, htile, xNbTilesWorld, yNbTilesWorld;
	Board& board = Singleton<Board>::getInstance();
	EngineCore& engine = Singleton<EngineCore>::getInstance();

	xscroll = board.getScroll().x;
	yscroll = board.getScroll().y;
	wtile = board.getTile().w;
	htile = board.getTile().h;
	xNbTilesWorld = board.getNbTilesWorld().x;
	yNbTilesWorld = board.getNbTilesWorld().y;


	if (x == 0)
		xscroll -= 60;
	if (x >= engine.getWidth() - 1)
		xscroll += 60;
	if (y == 0)
		yscroll -= 60;
	if (y >= engine.getHeight() - 1)
		yscroll += 60;
	

	if (xscroll <= 0)
		xscroll = 0;
	if (yscroll <= 0)
		yscroll = 0;
	if (xscroll >= xNbTilesWorld * wtile - engine.getWidth() - 1)
		xscroll = xNbTilesWorld * wtile - engine.getWidth() - 1;
	if (yscroll >= yNbTilesWorld * htile - engine.getHeight() - 1)
		yscroll = yNbTilesWorld * htile - engine.getHeight() - 1;


	board.setScroll(xscroll, yscroll);
}


Timer Game::getTimer()
{
	return timer;
}

