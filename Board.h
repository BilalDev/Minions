#ifndef BOARD_H
#define BOARD_H

#include "Singleton.h"
#include "headers.h"
#include "XMLParser.h"




class Board : public Singleton<Board>
{
friend class Singleton<Board>;

public:
	struct Block
	{
		int x, y;
		SDL_Rect texture;
		Block(int x = 0, int y = 0, SDL_Rect texture = {0, 0}) : x(x), y(y), texture(texture) {}
	};
	struct Tile
	{
		int w, h;
		Tile(int w = 0, int h = 0) : w(w), h(h) {}
	};
	struct NbTiles
	{
		int x, y;
		NbTiles(int x = 0, int y = 0) : x(x), y(y) {}
	};
	struct Scroll
	{
		int x, y;
		Scroll(int x = 0, int y = 0) : x(x), y(y) {}
	};
	struct NbTilesWorld
	{
		int x, y;
		NbTilesWorld(int x = 0, int y = 0) : x(x), y(y) {}
	};


private:
	Board(const Board&){};
	Board();
	~Board();


public:
	bool				init();
	SDL_Surface			*getTileset();
	void				setTileset(std::string);
	Tile				const& getTile();
	void				setTile(Tile const&);
	NbTiles				const& getNbTiles();
	void				setNbTiles(NbTiles const&);
	Scroll				const& getScroll();
	void				setScroll(Scroll const&);
	void				setScroll(int x, int y);
	NbTilesWorld		const& getNbTilesWorld();
	void				setNbTilesWorld(NbTilesWorld const&);
	std::list<Block>	&getMap();


private:
	Tile				tile;
	NbTiles				nbTiles;
	Scroll				scroll;
	NbTilesWorld		nbTilesWorld;
	SDL_Surface			*tileset;
	std::list<Block>	map;
};

#endif /* !#define BOARD_H */