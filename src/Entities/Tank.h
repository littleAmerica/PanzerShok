#ifndef _Tank_H_
#define _Tank_H_

#include "Entity.h"
#include "Turret.h"
#include "EventListener.h"

class Tank	:
	public Entity_Base
{
public:
	Tank(float x, float y);	

	virtual void draw(Screen* pScreen, Camera* pCamera = NULL); 

	virtual void lookAt(Vec2 coord);

protected:
	virtual Vec2 turretJoinGlobal(); //the place where the turret is joint to tank body
	virtual void attachTurret(Turret* turret);

	TurretPtr m_turret;
};

#endif