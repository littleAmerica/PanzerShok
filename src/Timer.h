#ifndef TIMER_H_
#define TIMER_H_

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

#endif // TIMER_H_
