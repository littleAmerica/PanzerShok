#include "GameObject.h"

#include "PhysEngine.h"
#include "RenderEngine.h"

#include "States.h"
#include "SDL.h"




GameObject::GameObject(int x /*= 0*/, int y /* = 0*/)
{
	m_maxForwardSpeed = 100;
	m_maxBackwardSpeed = -10;
	m_maxDriveForce = 150000;
	m_rect = Rect_t(0, 16, 0, 16);



	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(x, y);
	bodyDef.type = b2_dynamicBody;
	m_body = m_physEngine->world()->CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox( m_rect.x2 / 2, m_rect.y2 / 2);
	m_body->CreateFixture(&polygonShape, 1);//shape density
}



b2Vec2 GameObject::lateralVelocity()
{
	b2Vec2 currentRightNormal = m_body->GetWorldVector( b2Vec2(1,0) );
	return b2Dot( currentRightNormal, m_body->GetLinearVelocity() ) * currentRightNormal;
}

b2Vec2 GameObject::forwardVelocity()
{
	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
	return b2Dot( currentForwardNormal, m_body->GetLinearVelocity() ) * currentForwardNormal;
}



void GameObject::updateFriction()
{
	//lateral linear velocity
	float maxLateralImpulse = 25.f;
	b2Vec2 impulse = m_body->GetMass() * -lateralVelocity();
	if ( impulse.Length() > maxLateralImpulse )
		impulse *= maxLateralImpulse / impulse.Length();
	m_body->ApplyLinearImpulse( impulse, m_body->GetWorldCenter(), true);

	//angular velocity
	m_body->ApplyAngularImpulse( 0.1f * m_body->GetInertia() * -m_body->GetAngularVelocity(), true);

	//forward linear velocity

	//std::cout << "forward velocity: x = " << currentForwardNormal.x << " y = " << currentForwardNormal.y << "\n";

	//forward linear velocity
	b2Vec2 currentForwardNormal = forwardVelocity();
	float currentForwardSpeed = currentForwardNormal.Normalize();
	float dragForceMagnitude = -2 * currentForwardSpeed;
	m_body->ApplyForce( dragForceMagnitude * currentForwardNormal, m_body->GetWorldCenter(), true );

	std::cout << m_body->GetWorldCenter().x << " " << m_body->GetWorldCenter().y << "\n";
}

b2Vec2 GameObject::center()
{
	b2Vec2 center = m_body->GetWorldCenter();
	return center;
}

float GameObject::angle()
{
	return m_body->GetAngle();
}

Rect_t GameObject::rect()
{
	return m_rect;
}

GameObject::~GameObject()
{

}

void GameObject::update(float deltaTime)
{
	updateFriction();	
}
