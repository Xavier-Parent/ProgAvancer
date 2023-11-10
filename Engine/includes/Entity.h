#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"

class Entity final
{
public:
	Entity(const std::string& name);
	~Entity() = default;

	template<typename T>
	T* AddComponent() {
		T* cmp = new T(this);
		const type_info* type = &typeid(*cmp);
		m_Components[type] = cmp;

		IUpdatable* u_cmp = dynamic_cast<IUpdatable*>(cmp);
		if (u_cmp != nullptr)
		{
			m_Updatable.push_back(u_cmp);
		}

		IDrawable* d_cmp = dynamic_cast<IDrawable*>(cmp);
		if (d_cmp != nullptr)
		{
			m_Drawable.push_back(d_cmp);
		}
		return cmp;
	}

	template<typename T>
	T* GetComponent()
	{
		const type_info* type = &typeid(T);

		if (m_Components.count(type) > 0)
		{
			return static_cast<T*>(m_Components[type]);
		}
		else
		return nullptr;
	}

	void Start() {}

	void Update(float dt);
	void Draw();
	float GetX() { return x; }
	float GetY() { return y; }

	void SetPosition(float x,float y );
	void Destroy() {}
	std::string& GetName() { return m_Name; }
private:
	float x;
	float y;
	std::map<const type_info*, Component*> m_Components;
	std::vector<IDrawable*> m_Drawable;
	std::vector<IUpdatable*> m_Updatable;
	std::string m_Name;

};

