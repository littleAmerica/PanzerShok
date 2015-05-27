#ifndef _PHYS_ENGINE_
#define _PHYS_ENGINE_

#include "Box2D.h"

#include "Singleton.h"

class PhysEngine
{
private:
	PhysEngine();
	
public:
	static PhysEngine& Instance();

	void init();

	void step(float timeStep);

	void clean();

private:
	b2World* m_world;
	int32 m_velocityIterations;
	int32 m_positionIterations;
};

template<> void anFill<PhysEngine>(An<PhysEngine>& renderEngine);


#endif 