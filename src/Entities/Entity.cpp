#include "Entities/Entity.h"

#include "Physics/PhysEngine.h"
#include "RenderEngine.h"
#include "TextureManager.h"

#include "Camera.h"
#include "Screen.h"
#include "States.h"
#include "Utils/SDL_platform.h"
#include "Utils/Resources.h"
#include "Utils/Asserts.h"
#include "Texture.h"

#include <iostream>

static PhysicInfo defaultPhysicInfo = {Rect_t(0, 0, 16, 16), 3.14f/2};


Entity_Base::Entity_Base(float x, float y, Enity_Info* info) 
	:m_body(),
	m_id(ID_counter++)
{
	if (info && info->type == Enity_Info::eKinematic)
	{
		m_body.reset(new Physics_Kinematic(defaultPhysicInfo, x, y));
	}
	m_body.reset(new Physics_Rigid(defaultPhysicInfo, x, y));
	

	m_body->setEntityID(m_id);

	m_EngineForce = 150000;
	m_Cbraking = 50000;

	m_textureID = 1;

	float m_Cdrag = 0.5;		//Air Drag Constant
	float m_Crr = m_Cdrag * 30; // Rolling Resistance Constant

	ASSERT(m_body);
}


void Entity_Base::updateFriction()
{
	//lateral linear velocity
	// cut off the lateral moving
	float maxLateralImpulse = 25.f;
	Vec2 impulse = m_body->mass() * - m_body->lateralVelocity();
	m_body->applyLinearImpulse(impulse);

	// angular velocity
	m_body->applyAngularImpulse( 0.1f * m_body->inertia() * - m_body->angularVelocity());

	//==================================
	//Air drag
	//Fdrag = - Cdrag * v * |v|
	
	// Air Drag Constant
	// Cdrag = 0.5 * Cd * A * rho, 
	//	where	Cd - coefficient of friction, 
	//			A - frontal area of car, 
	//			rho - density of air (1.29) 
	Vec2 speed =  m_body->forwardVelocity();
	b2Vec2 Fdrag = - m_Cdrag * speed.Length() * speed;

	//==================================
	//The friction of the wheels (Rolling Resistance Constant)
	//Frr = - Crr * v 
	b2Vec2 Frr = - m_Crr * speed; 

	m_body->applyForce( Fdrag + Frr);

}

Vec2 Entity_Base::center()
{
	Vec2 center = m_body->worldCenter();
	return center;
}

float Entity_Base::angle()
{
	return m_body->angle();
}

Rect_t Entity_Base::bounds()
{
	return m_body->bounds();
}

Entity_Base::~Entity_Base()
{

}


void Entity_Base::update(float deltaTime)
{
	updateFriction();	
}

void Entity_Base::draw(Screen* pScreen, Camera* pCamera /*= NULL*/)
{
	//temporary, until we get animator class/texture manager and etc;
	//Texture text_;
	//text_.loadImage(kResourceFolder + "tank1.png");

	TexturePtr text = m_textureManager->GetTexture(m_textureID);

	Rect_t dest = boundsWord();

	if(pCamera)
		dest = pCamera->world2camera(dest);
	
	if (pScreen)
		pScreen->renderImage(*text, dest, angle());//Radian2Degree(angle()) + 180, NULL, SDL_FLIP_NONE);
}

int Entity_Base::id()
{
	return m_id;
}

Rect_t Entity_Base::boundsWord()
{
	Rect_t _bounds = bounds();
	Vec2 _center = center();
	Rect_t global(_center.x - _bounds.w / 2, _center.y - _bounds.h / 2, _bounds.w,_bounds.h);
	return global;
}

void Entity_Base::setTexture(int texture)
{
	m_textureID = texture;
}

PhysicsPtr Entity_Base::body()
{
	return m_body;
}

int Entity_Base::ID_counter = 0;
