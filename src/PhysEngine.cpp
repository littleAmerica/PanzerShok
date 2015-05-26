#include "PhysEngine.h"
#include "Box2D.h"


PhysEngine& PhysEngine::Instance()
{
	static PhysEngine instance;

	return instance;
}


PhysEngine::PhysEngine()
{

}

void PhysEngine::step()
{

}

