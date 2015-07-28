#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>

#include "Physics/Physics_Rigid.h"

class Camera;
class Screen;

class Entity;
typedef std::shared_ptr<Entity> EntityPtr;


class Entity
{
public:
	virtual ~Entity(){}

	//need to figure out what exactly the update wants to get (int?)
	virtual void update(float deltaTime) = 0; 
	virtual void draw(Screen* pScreen, Camera* pCamera = NULL) = 0;
	
	virtual int id() = 0;

	//virtual Rect_t boundsWord() = 0;
	//virtual	Rect_t	bounds() = 0;
	//virtual Vec2	center() = 0;
	//virtual float	angle() = 0;
};



class Entity_Base: public Entity
{
public:
	Entity_Base(float x, float y);
	virtual ~Entity_Base();

	//the update by default applies friction slow mechanism
	virtual void update(float deltaTime); 
	void draw(Screen* pScreen, Camera* pCamera = NULL);
	

	virtual Vec2	center();
	float	angle();
	virtual Rect_t	bounds();
	virtual Rect_t boundsWord();

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


//class Entity_Actor: public Entity
//{
//public:
//	Entity_Actor(int x = 100, int y = 100);
//	virtual ~Entity_Actor();
//
//	//the update by default applies friction slow mechanism
//	virtual void update(float deltaTime); 
//	virtual void draw();
//
//
//	Vec2	center();
//	float	angle();
//	Rect_t	bounds();
//
//protected:
//	virtual void	updateFriction();
//
//	Physics_Rigid m_body;
//
//	float m_maxForwardSpeed;
//	float m_maxBackwardSpeed;
//	float m_maxDriveForce;
//
//	An<PhysEngine>	m_physEngine;
//};

#endif // ENTITY_H_
