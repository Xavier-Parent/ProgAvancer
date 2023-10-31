#pragma once
#include "Entity.h"

class IUpdatable
{
public:
	virtual void Update(float dt) = 0;

};

class IDrawable
{
public:
	virtual void Draw() = 0;
};

class Component
{
public:
	~Component() {}

	Component(Entity* parent) {
		m_Entity = parent;
	}

	virtual void Start() = 0;
	virtual void Destroy() = 0;

protected:
	Entity* m_Entity;
};
