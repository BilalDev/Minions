#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <tinyxml.h>
#include "headers.h"
#include "Board.h"

class XMLParser
{
public:
	XMLParser();
	~XMLParser();
	
	bool parseLevel(std::string file);
};

#endif /* !XMLPARSER_H */