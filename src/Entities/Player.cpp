#include "Player.h"

#include "States.h"
#include <math.h>

void Player::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{
	switch (sym)
	{
	case SDLK_w: m_state |= UP; break;
	case SDLK_s: m_state |= DOWN; break;
	case SDLK_a: m_state |= LEFT; break;
	case SDLK_d: m_state |= RIGHT; break;
	default:
		break;
	}

}

void Player::OnKeyUp(SDL_Keycode sym, Uint16 mod)
{
	switch (sym)
	{
	case SDLK_w: m_state &= ~UP; break;
	case SDLK_s: m_state &= ~DOWN; break;
	case SDLK_a: m_state &= ~LEFT; break;
	case SDLK_d: m_state &= ~RIGHT; break;
	default:
		break;
	}
}

Player::Player(float x, float y) :
	Tank(x, y)
{
	
}


void Player::update(float deltaTime)
{
	Tank::update(deltaTime);
}

void Player::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle)
{
	lookAt(Vec2(mX, mY));
}
