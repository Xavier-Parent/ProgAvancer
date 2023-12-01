#pragma once
#include"Entity.h"
#include "IScene.h"
class IWorld
{
public:
	/// <summary>
	/// Register 
	/// </summary>
	/// <param name="name">Set the name of the scene</param>
	/// <param name="scene">The Scene to register</param>
	virtual void Register(const std::string& name, IScene* scene) = 0;
	/// <summary>
	/// Function to Load a scene
	/// </summary>
	/// <param name="scene">Name of the scene who is gonna be load</param>
	virtual void Load(const std::string& scene) = 0;
	/// <summary>
	/// Remove an Entity
	/// </summary>
	/// <param name="entity">The Entity to remove</param>
	virtual void Remove(Entity* entity) = 0;
	/// <summary>
	/// Function to call the update of scene
	/// </summary>
	/// <param name="dt">Delta time</param>
	virtual void Update(float dt) = 0;
	/// <summary>
	///  Function to Draw what is in the world
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// Function to search and find Entity in a scene
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	virtual Entity* Find(const std::string& name) = 0;
	/// <summary>
	/// Function to Create new entity
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	virtual Entity* Create(const std::string& name) = 0;
	/// <summary>
	/// Function to Unload the Entity in the world
	/// </summary>
	virtual void Unload() = 0;
	/// <summary>
	/// Function to Clean the Entity in the World
	/// </summary>
	virtual void CleanEntities() = 0;
	/// <summary>
/// Enable the start function of the Entity
/// </summary>
	virtual void StartEntities() = 0;
	/// <summary>
	/// Function to Unload the Scene and delete them
	/// </summary>
	virtual void Shutdown() = 0;
};

