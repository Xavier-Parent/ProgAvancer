#include "Entity.h"


Entity::Entity(const std::string& name)
	:x (0), y (0), m_Name(name)
{
	x = 0;
	y = 0;
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

void Entity::SetPosition(float X, float Y)
{
	x = X;
	y = Y;
}
