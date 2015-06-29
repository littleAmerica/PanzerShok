#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

#include <memory>
#include <string>

//TODO //remove it from header
#include "Box2D.h"

#include "States.h"
#include "Types.h"

#include <iostream>

#include "PhysEngine.h"


class GameObject {
public:
	GameObject(int x = 100, int y = 100);
	virtual ~GameObject();

	//need to figure out what exactly the update wants to get (int?)
	//the update by default applies friction slow mechanism
	virtual void update(float deltaTime); 

	b2Vec2	center();
	float	angle();
	Rect_t	rect();

protected:
	virtual void	updateFriction();

	virtual b2Vec2	lateralVelocity();
	virtual b2Vec2	forwardVelocity();

	b2Body* m_body;
	float m_maxForwardSpeed;
	float m_maxBackwardSpeed;
	float m_maxDriveForce;
	
	Rect_t m_rect;

	An<PhysEngine>	m_physEngine;
};

#endif