#ifndef BOARD_H
#define BOARD_H

#include "Singleton.h"
#include "headers.h"
#include "XMLParser.h"


class Board : public Singleton<Board>
{
friend class Singleton<Board>;

private:
	Board(const Board&){};
	Board();
	~Board();


public:
	bool						init();
	int							getTileW(), getTIleH();
	int							getNbTilesX(), getNbTilesY();
	SDL_Surface					*getTileset();
	std::vector<SDL_Rect, int>	*getProps();
	unsigned char				**getSchema();
	int							getXScroll(), getYScroll();
	int							getNbTilesWorldX(), getNbTilesWorldY();
	int							getWindowW(), getWindowH();

private:
	int							tile_w, tile_h;
	int							nbTilesX, nbTilesY;
	SDL_Surface					*tileset;
	std::vector<SDL_Rect, int>	*props;
	unsigned char				**schema;
	int							xScroll, yScroll;
	int							nbTilesWorldX, nbTilesWorldY;
	int							window_w, window_h;
	XMLParser					parser;
};

#endif /* !#define BOARD_H */