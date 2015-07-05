#ifndef _Player_H_
#define _Player_H_

#include "Entity.h"
#include "EventListener.h"

class Player : 
	public Entity_Base,
	public EventListener 
{
public:
	Player(float x, float y);

	//GameObject
	virtual void update(float deltaTime); 

	//EventListener
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);
	virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);

private:
	void	updateDrive();
	void	updateTurn();

	int state;  //temporary, show the buttons currently pressed  
};


#endif