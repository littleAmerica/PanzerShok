#include "Bullet.h"

static Physic_Info BulletInfo = {Rect_t(0, 0, 4, 4), 3.14f/2};

Bullet::Bullet(Vec2 place, float angle, Bullet_Info* info) :
	Entity_Base(place, info)
{
	m_textureID = 3;
	m_velocity = 5000;
	
	Vec2 vel = Vec2(-m_velocity * sin(angle), m_velocity * cos(angle));

	m_body->setLinearVelocity(vel);
	m_body->setAngle(angle + 3.14f);
}
