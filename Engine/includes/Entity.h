#pragma once
#include <iostream>
#include "Component.h"
#include <vector>
class Entity final
{
public:
	Entity(const std::string& name) : m_Name(name) {}
	virtual ~Entity() = default;
	void AddComponent(Component* cmp){m_Components.emplace_back(cmp);}
	virtual void Start() {}
	virtual void Update(float dt) {}
	virtual void Draw() {}
	virtual void Destroy() {}
	std::string& GetName() { return m_Name; }
private:
	void AddComponent(Component*);
	std::vector<Component*> m_Components;

	std::string m_Name;

};

