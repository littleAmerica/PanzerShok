#ifndef _Turret_H_
#define _Turret_H_

#include "Entities/Entity.h"

#include <memory>

struct Turret_Info
	: public Entity_Info
{

};

class Turret;
typedef std::shared_ptr<Turret> TurretPtr;

class Turret
	: public Entity_Base
{
public:
	Turret(Vec2 pos, Turret_Info& info); 	
	virtual void lookAt(Vec2 coord);
	virtual void fire();
protected:
	virtual Vec2 firePlace(); // the place from which the bullet starts moving (end of the cannon)

	Vec2 m_lookAt;
};


#endif