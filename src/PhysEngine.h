#ifndef _PHYS_ENGINE_
#define _PHYS_ENGINE_

#include "Box2D.h"

class PhysEngine
{
private:
	PhysEngine();
	
public:
	PhysEngine& Instance();

	void init();

	void step(float timeStep);

	void Dispose();

private:
	b2World* m_world;
	int32 m_velocityIterations;
	int32 m_positionIterations;
};


#endif 