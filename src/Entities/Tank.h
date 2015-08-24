#ifndef _Tank_H_
#define _Tank_H_

#include "Entity.h"
#include "Turret.h"
#include "EventListener.h"

struct Tank_Info : public Entity_Info
{
	float engineForce;
	float Cbraking;
	float Cdrag;	//Air Drag Constant
	float Crr;		// Rolling Resistance Constant
};

class Tank;
typedef std::shared_ptr<Tank> TankPtr;

class Tank	:
	public Entity_Base
{
public:
	Tank(Vec2 pos, Tank_Info* = NULL);	

	virtual void draw(Screen* pScreen, Camera* pCamera = NULL); 
	virtual void update(float deltaTime);
	
	virtual void updateState(int state);
	virtual int state();

	virtual void lookAt(Vec2 coord);
	virtual void fire();

protected:
	virtual Vec2 turretJoinGlobal(); //the place where the turret is joint to tank body
	virtual void attachTurret(Turret* turret);
	virtual void	updateFriction();
	void	updateDrive();
	void	updateTurn(float deltaTime);

	int	m_state;

	Tank_Info m_tankInfo;

	TurretPtr m_turret;
};

#endif