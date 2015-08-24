#ifndef _Player_H_
#define _Player_H_

#include "Tank.h"
#include "EventListener.h"


//TODO
//inheritance from Tank probably is temporary. Need to make own class with tank as a field
class Player : 
	public EventListener 
{
public:
	Player(float x, float y);

	//GameObject
	virtual void update(float deltaTime); 
	virtual EntityPtr entity();

	//EventListener
	virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);
	virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);
	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
	void OnLButtonDown(int mX, int mY);
private:
	TankPtr m_tank;
};


#endif