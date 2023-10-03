#pragma once

class Entity;
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

class Component : public IDrawable, public IUpdatable
{
public: 
	virtual ~Component() = default;
	Component();
	Component(Entity* parent);

protected:
};