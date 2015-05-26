#ifndef _PHYS_ENGINE_
#define _PHYS_ENGINE_

class PhysEngine
{
private:
	PhysEngine();

public:
	PhysEngine& Instance();

	void step();
};


#endif 