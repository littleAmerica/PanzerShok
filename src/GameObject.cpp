#include "GameObject.h"

#include "PhysEngine.h"
#include "RenderEngine.h"

#include "GameObjectContext.h"

#include "States.h"
#include "SDL.h"

static float maxForwardSpeed = 10;
static float maxBackwardSpeed = -20;
static float maxDriveForce = 10;

GameObject::GameObject()
{
	m_maxForwardSpeed = maxForwardSpeed;
	m_maxBackwardSpeed = maxBackwardSpeed;
	m_maxDriveForce = maxDriveForce;

	m_weight = 20;

	m_width = 32;
	m_height = 32;
}

GameObject::~GameObject()
{	
}




b2Vec2 GameObject::getLateralVelocity(GameObjectContext* context)
{
	b2Vec2 currentRightNormal = context->body()->GetWorldVector( b2Vec2(1,0) );
	return b2Dot( currentRightNormal, context->body()->GetLinearVelocity() ) * currentRightNormal;
}

b2Vec2 GameObject::getForwardVelocity(GameObjectContext* context)
{
	b2Vec2 currentForwardNormal = context->body()->GetWorldVector( b2Vec2(0,1) );
	return b2Dot( currentForwardNormal, context->body()->GetLinearVelocity() ) * currentForwardNormal;
}

void GameObject::updateFriction(GameObjectContext* context)
{
	//lateral linear velocity
	float maxLateralImpulse = 2.5f;
	b2Vec2 impulse = context->body()->GetMass() * -getLateralVelocity(context);
	if ( impulse.Length() > maxLateralImpulse )
		impulse *= maxLateralImpulse / impulse.Length();
	context->body()->ApplyLinearImpulse( impulse, context->body()->GetWorldCenter(), true );

	//angular velocity
	context->body()->ApplyAngularImpulse( 0.1f * context->body()->GetInertia() * - context->body()->GetAngularVelocity(), true );

	//forward linear velocity
	b2Vec2 currentForwardNormal = getForwardVelocity(context);
	float currentForwardSpeed = currentForwardNormal.Normalize();
	float dragForceMagnitude = -2 * currentForwardSpeed;
	context->body()->ApplyForce( dragForceMagnitude * currentForwardNormal, context->body()->GetWorldCenter(), true );
}

void GameObject::updateDrive(GameObjectContext* context, int controlState) {

	//find desired speed
	float desiredSpeed = 0;
	switch ( controlState & (UP|DOWN) ) {
	case UP:   desiredSpeed = m_maxForwardSpeed;  break;
	case DOWN: desiredSpeed = m_maxBackwardSpeed; break;
	default: return;//do nothing
	}

	//find current speed in forward direction
	b2Vec2 currentForwardNormal = context->body()->GetWorldVector( b2Vec2(0,1) );
	float currentSpeed = b2Dot( getForwardVelocity(context), currentForwardNormal );

	//apply necessary force
	float force = 0;
	if ( desiredSpeed > currentSpeed )
		force = m_maxDriveForce;
	else if ( desiredSpeed < currentSpeed )
		force = -m_maxDriveForce;
	else
		return;
	context->body()->ApplyForce( force * currentForwardNormal, context->body()->GetWorldCenter(), true );
}

void GameObject::updateTurn(GameObjectContext* context, int controlState) {
	float desiredTorque = 0;
	switch ( controlState & (LEFT|RIGHT) ) 
	{
		case LEFT:  
			desiredTorque = 15;  
			break;
		case RIGHT: 
			desiredTorque = -15; 
			break;
	default: ;//nothing
	}
	context->body()->ApplyTorque( desiredTorque , true);
}

