#include <vector>
#include "Entity.h"
#include <map>
#include "IScene.h"
class WorldService {
public:
	WorldService();
	~WorldService();

	void Add(Entity* entity);
	void Register(const std::string& name, IScene* scene);
	void Load(const std::string& scene);
	void Update(float dt);
	void Unload();
	void Remove(Entity* entity);
	Entity* Find(const std::string& name);
	Entity* Create(const std::string& name);

private:
	std::map<std::string, IScene*> m_Scenes;
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
	IScene* m_CurrentScene = nullptr;
};