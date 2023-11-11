#pragma once

class Entity;
/// <summary>
/// Class for the component who have Update
/// </summary>
class IUpdatable
{
public:
	/// <summary>
	/// Update virtual pure who need override
	/// </summary>
	/// <param name="dt"></param>
	virtual void Update(float dt) = 0;

};
/// <summary>
/// Class for component with Draw
/// </summary>
class IDrawable
{
public:
	/// <summary>
	/// Draw virtual pure who need override
	/// </summary>
	virtual void Draw() = 0;
};

class Component
{
public:
	/// <summary>
	/// Constructor by default
	/// </summary>
	Component() = default;
	/// <summary>
	/// Destructor by default
	/// </summary>
	virtual ~Component() = default;
	/// <summary>
	/// Constructor with entity
	/// </summary>
	/// <param name="parent"></param>
	Component(Entity* parent) {
		m_Entity = parent;
	}
	/// <summary>
	/// Function start virtual pure who need override
	/// </summary>
	virtual void Start() = 0;
	/// <summary>
	/// Fonction Destroy virtual pure who need override
	/// </summary>
	virtual void Destroy() = 0;

protected:
	Entity* m_Entity;
};
