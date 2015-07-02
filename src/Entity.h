#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_


#include <memory>
#include "Physics/Physics_Rigid.h"


class Entity;
typedef std::shared_ptr<Entity> EntityPtr;


class Entity
{
public:
	virtual ~Entity(){}

	//need to figure out what exactly the update wants to get (int?)
	virtual void update(float deltaTime) = 0; 
	virtual void draw() = 0;
	virtual int id() = 0;
};



class Entity_Base: public Entity
{
public:
	Entity_Base(int x = 100, int y = 100);
	virtual ~Entity_Base();

	//the update by default applies friction slow mechanism
	virtual void update(float deltaTime); 
	virtual void draw();
	

	b2Vec2	center();
	float	angle();
	Rect_t	bounds();

	virtual	int id();

protected:
	virtual void	updateFriction();

	std::shared_ptr<Physics> m_body;

	float m_maxForwardSpeed;
	float m_maxBackwardSpeed;
	float m_maxDriveForce;

	const int m_id;	
	static int ID_counter;

	An<PhysEngine>	m_physEngine;
};


class Entity_Actor: public Entity
{
public:
	Entity_Actor(int x = 100, int y = 100);
	virtual ~Entity_Actor();

	//the update by default applies friction slow mechanism
	virtual void update(float deltaTime); 
	virtual void draw();


	b2Vec2	center();
	float	angle();
	Rect_t	bounds();

protected:
	virtual void	updateFriction();

	Physics_Rigid m_body;

	float m_maxForwardSpeed;
	float m_maxBackwardSpeed;
	float m_maxDriveForce;

	An<PhysEngine>	m_physEngine;
};

#endif