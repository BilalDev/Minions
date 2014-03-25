#ifndef ENGINECORE_H
#define ENGINECORE_H

#include "Singleton.h"
#include "headers.h"
#include "Board.h"

class EngineCore : public Singleton<EngineCore>
{
friend class Singleton<EngineCore>;

private:
	EngineCore(const EngineCore&){};
	EngineCore();
	~EngineCore();

private:
	int screen_width;
	int screen_height;

public:
	int		getWidth();
	int		getHeight();
	bool	init();
	bool	update();
	void	close();

};

#endif /* !ENGINECORE_H */