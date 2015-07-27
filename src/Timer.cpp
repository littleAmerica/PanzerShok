#include "Timer.h"
#include "Utils/SDL_platform.h"

Timer::Timer()
{
	startTicks = 0;
	isStarted = false;
}

void Timer::start()
{
	isStarted = true;
	startTicks = SDL_GetTicks();
}

int Timer::ticks()
{
	//If the timer is running
	if( isStarted == true )
	{
		return SDL_GetTicks() - startTicks;
	}

	//If the timer isn't running
	return 0;
}

void Timer::wait(int ms)
{
	SDL_Delay(ms);
}
