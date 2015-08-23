#ifndef _Turret_H_
#define _Turret_H_

#include "Entities/Entity.h"

#include <memory>

struct Turret_Info
{

};

class Turret;
typedef std::shared_ptr<Turret> TurretPtr;

class Turret
	: public Entity_Base
{
public:
	Turret(float x, float y, const Turret_Info& info); 	
	virtual void lookAt(Vec2 coord);
	virtual void fire();
protected:
	Vec2 m_lookAt;
};


#endif