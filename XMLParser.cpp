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
	
	int nb_texture = std::stoi(elem->Attribute("nb_textures"));
	
	elem = hdl.FirstChildElement().FirstChildElement().FirstChildElement().Element();

	if (!elem)
	{
		std::cerr << "Le noeud n'existe pas." << std::endl;
		return false;
	}

	Board& board = Singleton<Board>::getInstance();

	for (int i = 0; i < nb_texture; ++i)
	{
		std::cout << elem->Attribute("img") << std::endl;
		elem = elem->NextSiblingElement();
	}

	while (elem)
	{
		std::cout << "Texture : " << elem->Attribute("texture") << 
		" X : " << elem->Attribute("x") << " Y : " << elem->Attribute("y") << std::endl;

		elem = elem->NextSiblingElement();
	}

	return true;
}