#include "WorldService.h"

void WorldService::Update(float dt)
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Update(dt);
	}
}

void WorldService::Shutdown()
{
	Unload();

	for (auto scene : m_Scenes)
	{
		delete scene.second;
	}

	m_Scenes.clear();
}

void WorldService::Load(const std::string& scene)
{
	if(m_Scenes[scene] != m_CurrentScene)
	{
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
	m_EntityMap.emplace(name, _e);
	return _e;
}

void WorldService::Draw() {
	for (auto entity : m_EntityInWorld) {
		entity->Draw();
	}
}


void WorldService::Remove(Entity* entity)
{
	for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it)
	{
		if (*it == entity)
		{
			m_EntityInWorld.erase(it);
			m_EntityMap.erase(entity->GetName());
			break;
		}
	}
}

void WorldService::Unload()
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Destroy();
		delete entity;
	}

	for (auto entity : m_EntityToStart)
	{
		delete entity;
	}

	for (auto entity : m_EntityToRemove)
	{
		entity->Destroy();
		delete entity;
	}

	m_EntityInWorld.clear();
	m_EntityMap.clear();
	m_EntityToStart.clear();
	m_EntityToRemove.clear();
}

void WorldService::CleanEntities()
{
	if (m_EntityToRemove.size() > 0)
	{
		std::vector<Entity*> _trash = m_EntityToRemove;
		m_EntityToRemove.clear();

		for (auto entity : _trash)
		{
			m_EntityMap.erase(entity->GetName());
			entity->Destroy();

			for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it)
			{
				if (entity == *it)
				{
					m_EntityInWorld.erase(it);
					delete entity;
					break;
				}
			}
		}
		_trash.clear();
	}
}

void WorldService::StartEntities()
{
	if (m_EntityToStart.size() > 0)
	{
		std::vector<Entity*> _starting = m_EntityToStart;
		m_EntityToStart.clear();

		for (auto entity : _starting)
		{
			if (m_EntityMap.count(entity->GetName()) > 0)
			{
				continue;
			}

			m_EntityInWorld.emplace_back(entity);
			m_EntityMap.emplace(entity->GetName(), entity);
		}

		for (auto entity : _starting)
		{
			entity->Start();
		}

		_starting.clear();
	}
}