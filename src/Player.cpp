#include "Player.h"

#include "States.h"

void Player::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{
	switch (sym)
	{
	case SDLK_w: state |= UP; break;
	case SDLK_s: state |= DOWN; break;
	case SDLK_a: state |= LEFT; break;
	case SDLK_d: state |= RIGHT; break;
	default:
		break;
	}

}

void Player::OnKeyUp(SDL_Keycode sym, Uint16 mod)
{
	switch (sym)
	{
	case SDLK_w: state &= ~UP; break;
	case SDLK_s: state &= ~DOWN; break;
	case SDLK_a: state &= ~LEFT; break;
	case SDLK_d: state &= ~RIGHT; break;
	default:
		break;
	}
}

Player::Player(float x, float y) :
	Entity_Base(x, y),
	state(0)
{
	
}


void Player::updateTurn(float deltaTime)
{

	float angulatAcceleration = 0;
	switch ( state & (LEFT|RIGHT) ) {
	case LEFT:  angulatAcceleration = -10;  break;
	case RIGHT: angulatAcceleration = +10; break;
	default: return;//nothing
	}
	float nextAngle = m_body->angle() + m_body->angularVelocity() / 60.0;
	float totalRotation = 15.f;
	
	float torque = m_body->inertia() * angulatAcceleration;
	m_body->applyTorque(torque);
}


void Player::updateDrive()
{
	if ((int)(state & UP)  == UP)
	{
		//Ftraction = u * Engineforce, 
		Vec2 Ftraction = m_EngineForce * m_body->forwardNormal(); 
		m_body->applyForce(Ftraction);
	}
	else if ((int)(state & DOWN) == DOWN)
	{
		//Fbraking = -u * Cbraking, 
		if(m_body->currentSpeed() > 5)
		{
			Vec2 Ftraction = - m_Cbraking * m_body->forwardNormal(); 
			m_body->applyForce(Ftraction);
		}
		else
		{
			m_body->stopMoving();
		}
	}
}

void Player::update(float deltaTime)
{
	updateDrive();
	updateTurn(deltaTime);
	Entity_Base::update(deltaTime);
}
