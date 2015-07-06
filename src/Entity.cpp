#include "Entity.h"

#include "Physics/PhysEngine.h"
#include "RenderEngine.h"

#include "Camera.h"
#include "Screen.h"
#include "States.h"
#include "SDL.h"
#include "Texture.h"

#include <iostream>

static PhysicInfo defaultPhysicInfo = {Rect_t(0, 0, 16, 16)};


Entity_Base::Entity_Base(float x /*= 100*/, float y /*= 100*/) :m_body(new Physics_Rigid(defaultPhysicInfo, x, y)),
	m_id(ID_counter++)
{
	if (!m_body)
		throw;

	m_body->setEntityID(m_id);

	m_maxForwardSpeed = 100;
	m_maxBackwardSpeed = -10;
	m_maxDriveForce = 150000;
}


void Entity_Base::updateFriction()
{
	//lateral linear velocity
	float maxLateralImpulse = 25.f;
	Vec2 impulse = m_body->mass() * - m_body->lateralVelocity();
	if ( impulse.Length() > maxLateralImpulse )
		impulse = maxLateralImpulse / impulse.Length() * impulse;
	 m_body->applyLinearImpulse(impulse);

	//angular velocity
	 m_body->applyAngularImpulse( 0.1f * m_body->inertia() * - m_body->angularVelocity());

	//forward linear velocity

	//std::cout << "forward velocity: x = " << currentForwardNormal.x << " y = " << currentForwardNormal.y << "\n";

	//forward linear velocity
	Vec2 currentForwardNormal = m_body->forwardVelocity();
	float currentForwardSpeed =  m_body->currentSpeed();
	currentForwardNormal.Normalize();
	float dragForceMagnitude = -2 * currentForwardSpeed;
	m_body->applyForce( dragForceMagnitude * currentForwardNormal);

	//std::cout << m_body->GetWorldCenter().x << " " << m_body->GetWorldCenter().y << "\n";
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
	Texture text_;
	text_.SetRenderer(RenderEngine::Instance().renderer());
	text_.loadImage(".\\resources\\tank1.png");



	Rect_t dest = boundsWord();

	if(pCamera)
		dest = pCamera->world2camera(dest);
	
	if (pScreen)
		pScreen->renderImage(text_, dest, angle());//Radian2Degree(angle()) + 180, NULL, SDL_FLIP_NONE);
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

int Entity_Base::ID_counter = 0;
