#ifndef TIMER_H
#define TIMER_H

#include "headers.h"

class Timer
{
public:
	Timer();
	~Timer();

	void	start();
	void	pause();
	void	unpause();
	void	stop();

	int		getTicks();
	bool	isPaused();
	bool	isStarted();


private:
	int		startTicks;
	int		pausedTicks;
	bool	paused;
	bool	started;
};

#endif /* !TIMER_H */
