#include "WorldService.h"

WorldService::WorldService()
{
}
WorldService::~WorldService()
{
}


void WorldService::Add(Entity* entity)
{
	m_EntityInWorld.emplace_back(entity);
	m_EntityMap.emplace(entity->GetName(), entity);
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
	if (m_Scenes.count(scene) > 0) {
		Unload();
		m_CurrentScene = m_Scenes[scene];
		m_CurrentScene->Load();
	}
}

void WorldService::Unload()
{
	if (m_CurrentScene != nullptr) {
		for (auto entity : m_EntityInWorld) {
			entity->Destroy();
			delete entity;
		}
		m_EntityInWorld.clear();
		m_EntityMap.clear();
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
	Add(_e);
	return _e;
	return nullptr;
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