#pragma once
#include <iostream>
#include "Component.h"
class Entity 
{
public:
	Entity(const std::string& name) : m_Name(name) {}
	virtual ~Entity() = default;

	virtual void Start() {}
	virtual void Update(float dt) {}
	virtual void Draw() {}
	virtual void Destroy() {}
	std::string& GetName() { return m_Name; }
private:
	//void AddComponent(Component*);
	std::string m_Name;

};

