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
