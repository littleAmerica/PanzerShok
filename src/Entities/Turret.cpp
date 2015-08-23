#include "Turret.h"

#include "States.h"
#include <math.h>


Turret::Turret(float x, float y, const Turret_Info& info)
	:Entity_Base(x, y)
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
