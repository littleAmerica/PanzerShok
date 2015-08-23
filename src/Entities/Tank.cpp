#include "Tank.h"
#include "States.h"

#include <math.h>
#include <iostream>


Tank::Tank(float x, float y)
	:	Entity_Base(x, y)
{
	Turret_Info turret_Info;
	Vec2 _center = center();
	Turret* turret = new Turret(_center.x, _center.y, turret_Info);
	turret->setTexture(2);

	attachTurret(turret);
}

void Tank::draw(Screen* pScreen, Camera* pCamera /*= NULL*/)
{
	Entity_Base::draw(pScreen, pCamera);
	m_turret->draw(pScreen, pCamera);
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
