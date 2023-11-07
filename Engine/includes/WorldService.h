#include <vector>
#include "Entity.h"
#include <map>
#include "IScene.h"
#include "IWorld.h"
class WorldService : public IWorld{
public:
	WorldService();
	~WorldService();

	virtual void Register(const std::string& name, IScene* scene) override;
	virtual void Draw() override;
	virtual void Load(const std::string& scene) override;
	virtual void Update(float dt) override;
	virtual void Remove(Entity* entity) override;

	virtual Entity* Find(const std::string& name) override;
	virtual Entity* Create(const std::string& name) override;

private:
	std::map<std::string, IScene*> m_Scenes;
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
	IScene* m_CurrentScene = nullptr;
};