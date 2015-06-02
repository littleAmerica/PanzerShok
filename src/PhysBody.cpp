//#include "PhysBody.h"
//#include "PhysEngine.h"
//
//
//PhysBody::PhysBody()
//	:m_body(0)
//{
//
//}
//
//Point PhysBody::getCenter()
//{
//	b2Vec2 center = m_body->GetWorldCenter();
//	return Point((int)center.x, (int)center.y);	
//}
//
////Rect PhysBody::getBounds()
////{
////	return Rect();
////}
//
//PhysBody::~PhysBody()
//{
//	dispose();
//}
//
//void PhysBody::dispose()
//{
//	if (m_body)
//	{
//		m_body->GetWorld()->DestroyBody(m_body);
//	}
//}
//
//
//
//
//void PhysBody::move(int state)
//{
//	float force = 200.f;
//
//	//find current speed in forward direction
//	b2Vec2 currentForwardNormal = m_body->GetWorldVector( b2Vec2(0,1) );
//
//	m_body->ApplyForce(force * currentForwardNormal, m_body->GetWorldCenter(), true);		
//}
//
////float PhysBody::getAngle()
////{
////	return 0;
////}
//
