#include "Player.h"

#include "States.h"
#include <math.h>

void Player::OnKeyDown(SDL_Keycode sym, Uint16 mod)
{
	int state = m_tank->state();
	switch (sym)
	{
	case SDLK_w: state |= UP; break;
	case SDLK_s: state |= DOWN; break;
	case SDLK_a: state |= LEFT; break;
	case SDLK_d: state |= RIGHT; break;
	default:
		break;
	}
	m_tank->updateState(state);
}

void Player::OnLButtonDown(int mX, int mY)
{
	m_tank->fire();
}


void Player::OnKeyUp(SDL_Keycode sym, Uint16 mod)
{
	int state = m_tank->state();
	switch (sym)
	{
	case SDLK_w: state &= ~UP; break;
	case SDLK_s: state &= ~DOWN; break;
	case SDLK_a: state &= ~LEFT; break;
	case SDLK_d: state &= ~RIGHT; break;
	default:
		break;
	}
	m_tank->updateState(state);
}


Player::Player(float x, float y)
{
	Tank_Info tank_info;
	tank_info.bounds = Rect_t(0, 0, 8, 8);

	tank_info.engineForce = 5000;
	tank_info.Cbraking = 2000;
	tank_info.Cdrag = 0.0;
	tank_info.Crr = 0;
	tank_info.textureID = 1;
	tank_info.type = Entity_Info::eRigid;


	m_tank.reset(new Tank(Vec2(x, y), &tank_info));
}


void Player::update(float deltaTime)
{
	m_tank->update(deltaTime);
}

void Player::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle)
{
	m_tank->lookAt(Vec2((float)mX, (float)mY));
}

EntityPtr Player::entity()
{
	return m_tank;
}
