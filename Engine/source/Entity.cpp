#include "Entity.h"


Entity::Entity(const std::string& name)
	:X (0), Y (0), m_Name(name)
{
	X = 0;
	Y = 0;
}

void Entity::Update(float dt)
{
	for (auto c : m_Updatable) {
		c->Update(dt);
	}
}


void Entity::Draw()
{
	for (auto c : m_Drawable) {
		c->Draw();
	}
}

void Entity::SetPosition(float x, float y)
{
	X = x;
	Y = y;
}


void Entity::Destroy()
{
	for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		it->second->Destroy();
		delete it->second;
	}

	m_Components.clear();
	m_Drawable.clear();
	m_Updatable.clear();
}

