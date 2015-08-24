#include "Turret.h"
#include "Bullet.h"
#include "EntityList.h"
#include <math.h>
#include <iostream>

Turret::Turret(Vec2 pos, Turret_Info& info) :
	Entity_Base(pos, &info)
{
	
}

void Turret::lookAt(Vec2 coord)
{
	Vec2 _center = center();

	float targetVectorX = coord.x - _center.x;
	float targetVectorY = coord.y - _center.y;

	float angle = atan2(targetVectorY, targetVectorX);

	m_body->setAngle(angle - 3.14f/2);
}

void Turret::fire()
{
	Bullet_Info info;
	info.type = Entity_Info::eRigid;
	info.bounds = Rect_t(0, 0, 8, 8);
	EntityPtr bullet = EntityPtr(new Bullet(firePlace(), angle(), &info));
	EntityList::instance().addGameObject(bullet);
}

Vec2 Turret::firePlace()
{
	Rect_t _bounds = bounds();
	float _angle = angle();
	Vec2 firePlace = center() + Vec2(-sin(_angle) * 12, cos(_angle) * 12);

	return firePlace;
}
