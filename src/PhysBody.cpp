#include "PhysBody.h"


PhysBody::PhysBody()
	:m_body(0)
{

}

Point PhysBody::getCenter()
{
	return Point();	
}

Rect PhysBody::getBounds()
{
	return Rect();
}

PhysBody::~PhysBody()
{
	dispose();
}

void PhysBody::dispose()
{
	if (m_body)
	{
//		m_physEngine->destroyPhysBody(this);
	}
}

