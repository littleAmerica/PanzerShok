#ifndef _PHYS_ENGINE_
#define _PHYS_ENGINE_

#include <memory>
#include <vector>

#include "Box2D.h"

#include "Singleton.h"
#include "PhysBody.h"

class PhysEngine
{
private:
	PhysEngine();
	~PhysEngine();
public:
	
	static PhysEngine& Instance();

	void init();
	void step(float timeStep);
	void clean();

	PhysBodyPtr createBoxPhysBody(const Point& Position, int width, int height);
	void destroyPhysBody(PhysBodyPtr body);


private:
	b2World* m_world;
	int32 m_velocityIterations;
	int32 m_positionIterations;
};

template<> void anFill<PhysEngine>(An<PhysEngine>& renderEngine);


#endif 