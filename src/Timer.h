#ifndef _TIMER_
#define _TIMER_

class Timer
{
public:
	Timer();

	void	start();
	int		ticks();
	void	wait(int ms);

private:
	int startTicks;
	bool isStarted;
};

#endif