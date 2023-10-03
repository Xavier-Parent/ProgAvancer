#pragma once
#include"Entity.h"
class IWorld
{
public:
	void Draw();
	void Update();
private:
	void Add(Entity*);
};

