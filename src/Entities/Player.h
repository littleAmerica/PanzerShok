#ifndef _Player_H_
#define _Player_H_

#include "Tank.h"
#include "EventListener.h"


//TODO
//inheritance from Tank probably is temporary. Need to make own class with tank as a field
class Player : 
	public Tank,
	public EventListener 
{
public:
	Player(float x, float y);

	//GameObject
	virtual void update(float deltaTime); 

	//EventListener
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);
	virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);
	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

private:
	void	updateDrive();
	void updateTurn(float deltaTime);

	int state;  //temporary, show the buttons currently pressed  
};


#endif