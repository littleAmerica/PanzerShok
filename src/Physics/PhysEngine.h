#ifndef _PHYS_ENGINE_
#define _PHYS_ENGINE_

#include <memory>
#include <vector>

#include "Box2D.h"
#include "../Game.h"

#include "../Singleton.h"

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

	int32 velocityIterations() const { return m_velocityIterations; }
	int32 positionIterations() const { return m_positionIterations; }
	
	void positionIterations(int32 val) { m_positionIterations = val; }
	void velocityIterations(int32 val) { m_velocityIterations = val; }
	
	b2World* world();

private:
	b2World* m_world;
	int32 m_velocityIterations;
	int32 m_positionIterations;

	Game* m_game;

};

template<> void anFill<PhysEngine>(An<PhysEngine>& renderEngine);


#endif 