#pragma once
#include <iostream>
#include "Component.h"
#include <vector>
#include <map>

class Entity final
{
public:
	Entity(const std::string& name) : m_Name(name) {}
	~Entity() = default;

	template<typename T>
	T* AddComponent(){
		T* cmp = new T();
		const type_info* type = &typeid(*cmp);
		m_Components[type] = cmp;

		IUpdatable* u_cmp = dynamic_cast<IUpdatable*>(cmp);
		if (u_cmp != nullptr)
		{
			m_Updatable[type] = u_cmp;
		}

		IDrawable* d_cmp = dynamic_cast<IDrawable*>(cmp);
		if (d_cmp != nullptr)
		{
			m_Updatable[type] = d_cmp;
		}
	}

	void Start() {}

	void Update(float dt) {
		for (auto c : m_Updatable) {
			c->Update(dt);
		}
	}
	void Draw() {
		for (auto c : m_Drawable) {
			c->Draw();
		}
	}

	void Destroy() {}
	std::string& GetName() { return m_Name; }
private:
	std::map<const type_info* , Component*> m_Components;
	std::vector<IDrawable*> m_Drawable;
	std::vector<IUpdatable*> m_Updatable;
	std::string m_Name;

};

