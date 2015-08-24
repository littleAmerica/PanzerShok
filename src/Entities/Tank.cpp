#include "Tank.h"
#include "States.h"

#include <math.h>
#include <iostream>


Tank::Tank(Vec2 pos, Tank_Info*tank_info/* = NULL*/):
	Entity_Base(pos, tank_info),
	m_state(0),
	m_tankInfo(*tank_info)
{
	Turret_Info turret_Info;
	turret_Info.bounds = Rect_t(0, 0, 8, 8);
	turret_Info.type = Entity_Info::eRigid;
	turret_Info.textureID = 2;

	Vec2 _center = center();
	Turret* turret = new Turret(_center, turret_Info);

	attachTurret(turret);
}

void Tank::draw(Screen* pScreen, Camera* pCamera /*= NULL*/)
{
	//std::cout << "Dest: " << boundsWord().x << " " << boundsWord().y << "---angle :" << angle() << "\n";
	Entity_Base::draw(pScreen, pCamera);
	m_turret->draw(pScreen, pCamera);
}

void Tank::updateFriction()
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
	b2Vec2 Fdrag = - m_tankInfo.Cdrag * speed.Length() * speed;

	//==================================
	//The friction of the wheels (Rolling Resistance Constant)
	//Frr = - Crr * v 
	b2Vec2 Frr = - m_tankInfo.Crr * speed; 

	std::cout << "speed: " << speed.x << " " << speed.y << "\n";

	//m_body->applyForce( Fdrag + Frr);
}

void Tank::update(float deltaTime)
{
	updateDrive();
	updateTurn(deltaTime);
	updateFriction();	
}


void Tank::updateTurn(float deltaTime)
{

	float angulatAcceleration = 0;
	switch ( m_state & (LEFT|RIGHT) ) {
	case LEFT:  angulatAcceleration = -10;  break;
	case RIGHT: angulatAcceleration = +10; break;
	default: return;//nothing
	}
	float nextAngle = m_body->angle() + m_body->angularVelocity() / 60.0;
	float totalRotation = 15.f;

	float torque = m_body->inertia() * angulatAcceleration;
	m_body->applyTorque(torque);
}


void Tank::updateDrive()
{
	if ((int)(m_state & UP)  == UP)
	{
		//Ftraction = u * Engineforce, 
		Vec2 Ftraction = m_tankInfo.engineForce * m_body->forwardNormal(); 
		//m_body->applyForce(Ftraction);
		m_body->setLinearVelocity(80 * m_body->forwardNormal());
	}
	else if ((int)(m_state & DOWN) == DOWN)
	{
		//Fbraking = -u * Cbraking, 
		if(m_body->currentSpeed() > 5)
		{
			Vec2 Ftraction = - m_tankInfo.Cbraking * m_body->forwardNormal(); 
			m_body->applyForce(Ftraction);
		}
		else
		{
			//m_body->stopMoving();
		}
	}
}


void Tank::attachTurret(Turret* turret)
{
	m_body->attachPhysics(turret->body().get(), turretJoinGlobal());
	m_turret.reset(turret);
}

Vec2 Tank::turretJoinGlobal()
{
	return center();
}

void Tank::lookAt(Vec2 coord)
{
	m_turret->lookAt(coord);
}

void Tank::fire()
{
	m_turret->fire();
}

void Tank::updateState(int state)
{
	m_state = state;
}

int Tank::state()
{
	return m_state;
}
