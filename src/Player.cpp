#include "Player.h"

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

Player::Player()
	:state(0)
{
	
}


void Player::updateTurn()
{

	float desiredTorque = 0;
	switch ( state & (LEFT|RIGHT) ) {
	case LEFT:  desiredTorque = -15 * 32 * 16 * 16;  break;
	case RIGHT: desiredTorque = +15 * 32 * 16 * 16; break;
	default: return;//nothing
	}
	m_body->ApplyTorque( desiredTorque , true);

	std::cout << m_body->GetAngle() << "\n";

}


void Player::updateDrive()
{
	//find desired speed
	float desiredSpeed = 0;
	switch ( state & (UP|DOWN) ) {
	case UP:   desiredSpeed = m_maxForwardSpeed;  break;
	case DOWN: desiredSpeed = m_maxBackwardSpeed; break;
	default: return;//do nothing
	}

	//find current speed in forward direction
	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
	float currentSpeed = b2Dot( forwardVelocity(), currentForwardNormal );

	//apply necessary force
	float force = 0;
	if ( desiredSpeed > currentSpeed )
		force = m_maxDriveForce;
	else if ( desiredSpeed < currentSpeed )
		force = -m_maxDriveForce;
	else
		return;
	m_body->ApplyForce( force * currentForwardNormal, m_body->GetWorldCenter(), true );

	//		std::cout << m_body->GetWorldCenter().x << " " << m_body->GetWorldCenter().y << "\n";
}

void Player::update(float deltaTime)
{
	updateDrive();
	updateTurn();
	GameObject::update(deltaTime);
}
