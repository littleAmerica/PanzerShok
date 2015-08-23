#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_


#include <memory>
#include "Physics/Physics_Rigid.h"

class Camera;
class Screen;
class TextureManager;

class Entity;
typedef std::shared_ptr<Entity> EntityPtr;


struct Enity_Info
{
	enum Type{
		eRigid,
		eKinematic
	};

	Type type;

	float engineForce;
	float Cbraking;
	float Cdrag;
	float Crr;
};


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
	Entity_Base(float x, float y, Enity_Info* info = NULL);
	virtual ~Entity_Base();

	//the update by default applies friction slow mechanism
	virtual void update(float deltaTime); 
	virtual void draw(Screen* pScreen, Camera* pCamera = NULL);
	
	//temporary
	virtual void setTexture(int texture);

	virtual Vec2	center();
	float	angle();
	virtual Rect_t	bounds();
	virtual Rect_t boundsWord();
	virtual PhysicsPtr body();
	
	virtual	int id();

protected:

	PhysicsPtr m_body;

	int m_textureID;

	const int m_id;	
	static int ID_counter;

	An<PhysEngine>	m_physEngine;
	An<TextureManager> m_textureManager;
};


#endif