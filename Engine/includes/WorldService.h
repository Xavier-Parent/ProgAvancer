#include <vector>
#include "Entity.h"
#include <map>
#include "IScene.h"
#include "IWorld.h"
class WorldService : public IWorld{
public:
	/// <summary>
	/// Constructor by Default
	/// </summary>
	WorldService();
	/// <summary>
	/// Destructor by Default
	/// </summary>
	~WorldService();
	/// <summary>
	/// Function to register a new scene
	/// </summary>
	/// <param name="name">The name of the scene who need to be register</param>
	/// <param name="scene">The Scene</param>
	virtual void Register(const std::string& name, IScene* scene) override;
	/// <summary>
	/// Function to Draw what is in the world
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// Function to Load Scene
	/// </summary>
	/// <param name="scene">The name of the scene who is gonna be call</param>
	virtual void Load(const std::string& scene) override;
	/// <summary>
	/// Function to call the update of scene
	/// </summary>
	/// <param name="dt">delatime</param>
	virtual void Update(float dt) override;
	/// <summary>
	/// Remove thing from the scene
	/// </summary>
	/// <param name="entity">The entity who is gonna be remove</param>
	virtual void Remove(Entity* entity) override;
	/// <summary>
	/// Function to search and find Entity in a scene
	/// </summary>
	/// <param name="name">The Entity who is gonna be find</param>
	/// <returns></returns>
	virtual Entity* Find(const std::string& name) override;
	/// <summary>
	/// Function to Create new entity
	/// </summary>
	/// <param name="name">The Entity</param>
	/// <returns></returns>
	virtual Entity* Create(const std::string& name) override;

private:
	std::map<std::string, IScene*> m_Scenes;
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
	IScene* m_CurrentScene = nullptr;
};