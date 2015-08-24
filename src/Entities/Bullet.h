#ifndef _BULLET_H_
#define _BULLET_H_


#include <memory>
#include "Entity.h"
#include "Physics/Physics_Rigid.h"

struct Bullet_Info
	: Entity_Info
{

};

class Bullet;
typedef std::shared_ptr<Bullet> BulletPtr;

class Bullet : public Entity_Base
{
public:
	Bullet(Vec2 place, float angle, Bullet_Info* info);
private:
	float m_velocity;
};

#endif