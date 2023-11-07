#pragma once
#include"Entity.h"
#include "IScene.h"
class IWorld
{
public:
	virtual void Register(const std::string& name, IScene* scene) = 0;
	virtual void Load(const std::string& scene) = 0;
	virtual void Remove(Entity* entity) = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual Entity* Find(const std::string& name) = 0;
	virtual Entity* Create(const std::string& name) = 0;
};

