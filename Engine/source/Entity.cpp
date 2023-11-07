#include "Entity.h"
#include "engin.h"


using namespace homer;

Entity::Entity(const std::string& name)
	:x (0), y (0), m_Name(name)
{
	x = 0;
	y = 0;
}

void Entity::Update(float dt)
{
	/*
	for (auto c : m_Updatable) {
		c->Update(dt);
	}
	*/
	


}


void Entity::Draw()
{
	/*for (auto c : m_Drawable) {
		c->Draw();
	}*/
	RectF _carre;
	_carre.x = x;
	_carre.y = y;
	_carre.h = 500;
	_carre.w = 500;
	Engin::Get()->Graphics().DrawTexture(Engin::Get()->Graphics().LoadTexture("assets/sprite/Candle.png"), _carre, Color::Red);
}
