#include "WorldService.h"

WorldService::WorldService()
{
}
WorldService::~WorldService()
{
}

void WorldService::Update(float dt)
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Update(dt);
	}
}


void WorldService::Load(const std::string& scene)
{
	//Unload();
	if (m_CurrentScene != nullptr) {
		for (auto entity : m_EntityInWorld) {
			entity->Destroy();
			delete entity;
		}
		m_EntityInWorld.clear();
		m_EntityMap.clear();
	}

	if (m_Scenes.count(scene) > 0) {
		m_CurrentScene = m_Scenes[scene];
		m_CurrentScene->Load();
	}
}

void WorldService::Register(const std::string& name, IScene* scene)
{
	if (m_Scenes.count(name) == 0) {
		m_Scenes[name] = scene;
	}
}

Entity* WorldService::Find(const std::string& name)
{
	if (m_EntityMap.count(name) > 0) {
		return m_EntityMap[name];
	}
	return nullptr;
}

Entity* WorldService::Create(const std::string& name)
{
	Entity* _e = new Entity(name);
	m_EntityInWorld.emplace_back(_e);
	m_EntityMap.emplace(_e->GetName(), _e);
	return _e;
}


void WorldService::Remove(Entity* entity)
{
	for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it)
	{
		if (*it == entity)
		{
			m_EntityInWorld.erase(it);
			break;
		}
	}
	m_EntityMap.erase(entity->GetName());
}