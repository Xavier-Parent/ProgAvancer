#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"

class Entity final
{
public:
	/// <summary>
	/// Constructor of an entity with is name
	/// </summary>
	/// <param name="name">name of the entity</param>
	Entity(const std::string& name);
	/// <summary>
	/// Destructor by default
	/// </summary>
	~Entity() = default;
	/// <summary>
	/// The function to add a component to the Entity
	/// </summary>
	/// <typeparam name="T">Type of the component if Updatable or Drawable</typeparam>
	/// <returns></returns>
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
	/// <summary>
	/// Function to Fetch the component in an entity
	/// </summary>
	/// <typeparam name="T">Return the type of the component</typeparam>
	/// <returns></returns>
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
	/// <summary>
	/// Function Start for an entity
	/// </summary>
	void Start() {}
	/// <summary>
	/// Function Update for an entity
	/// </summary>
	/// <param name="dt">delta time</param>
	void Update(float dt);
	/// <summary>
	/// function draw fo the entity
	/// </summary>
	void Draw();
	/// <summary>
	/// Function to return the position Horizontal of the Entity
	/// </summary>
	/// <returns>Return the X value</returns>
	float GetX() { return x; }
	/// <summary>
	/// Function to return the Vertical Position of the entity
	/// </summary>
	/// <returns>Return the Y value</returns>
	float GetY() { return y; }
	/// <summary>
	/// Function to set the position of the entity in the world
	/// </summary>
	/// <param name="x">Set the X position who is the Horizontal value</param>
	/// <param name="y">Set the Y position who is the Vertical value</param>
	void SetPosition(float x,float y );
	/// <summary>
	/// Destroy the Entity
	/// </summary>
	void Destroy() {}
	/// <summary>
	/// Function to get the name of the Entity
	/// </summary>
	/// <returns>Return the name of the Entity</returns>
	std::string& GetName() { return m_Name; }
private:
	float x;
	float y;
	std::map<const type_info*, Component*> m_Components;
	std::vector<IDrawable*> m_Drawable;
	std::vector<IUpdatable*> m_Updatable;
	std::string m_Name;

};

