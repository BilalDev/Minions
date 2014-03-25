#include "XMLParser.h"


XMLParser::XMLParser()
{}


XMLParser::~XMLParser()
{}


bool XMLParser::parseLevel(std::string file)
{
	TiXmlDocument doc(file.c_str());
	if (!doc.LoadFile())
	{
		std::cerr << "erreur lors du chargement" << std::endl;
		std::cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << std::endl;
		return false;
	}

	TiXmlHandle hdl(&doc);
	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();
	
	if (!elem)
	{
		std::cerr << "Le noeud n'existe pas." << std::endl;
		return false;
	}

	Board& board = Singleton<Board>::getInstance();


	// Set number of tiles x & y
	board.setNbTiles(Board::NbTiles(std::stoi(elem->Attribute("x")),
					std::stoi(elem->Attribute("y"))));
	
	// Set tile width & height
	board.setTile(Board::Tile(std::stoi(elem->Attribute("block_size_x")),
				std::stoi(elem->Attribute("block_size_y"))));

	// Set tileset filename
	elem = hdl.FirstChildElement().FirstChildElement().FirstChildElement().Element();
	if (!elem)
	{
		std::cerr << "Le noeud n'existe pas." << std::endl;
		return false;
	}
	board.setTileset(elem->Attribute("img"));
	elem = elem->NextSiblingElement();

	// Set properties of tiles
	for (int i = 0; i < board.getNbTiles().x; ++i)
	{
		for (int j = 0; j < board.getNbTiles().y; ++j)
		{
			elem = elem->NextSiblingElement();
		}
	}
	
	// Set block caracteristics
	SDL_Rect rect;
	rect.y = 0;
	rect.h = board.getTile().h;
	rect.w = board.getTile().w;
	int i = 0;
	while (elem)
	{
		// TODO split with ":" for rect.y
		rect.x = std::stoi(elem->Attribute("texture")) * board.getTile().w;

		board.getMap().push_back(Board::Block(std::stoi(elem->Attribute("x")),
								std::stoi(elem->Attribute("y")),
								rect));

		elem = elem->NextSiblingElement();
		++i;
	}
	
	board.setNbTilesWorld(Board::NbTilesWorld(33, 16));
	return true;
}
