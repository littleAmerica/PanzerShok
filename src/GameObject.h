#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include <memory>
#include <string>

//TODO //remove it from header
#include "Box2D.h"

class GameObjectContext;

class GameObject
{	
public:
	GameObject();	

	void move();
	float width()  { return m_width; }
	float weight() const { return m_weight; }
	float height() const { return m_height; }

	~GameObject();
	b2Vec2 getLateralVelocity(GameObjectContext* context);
	b2Vec2 getForwardVelocity(GameObjectContext* context);
	void updateFriction(GameObjectContext* context);
	void updateDrive(GameObjectContext* context, int controlState);
	void updateTurn(GameObjectContext* context, int controlState);
public:
	std::string name;

	float m_maxForwardSpeed;
	float m_maxBackwardSpeed;
	float m_maxDriveForce;
	
	float m_weight;
	float m_width;
	float m_height;
};

#endif