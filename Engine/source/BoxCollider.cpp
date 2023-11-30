#include "BoxCollider.h"
//#include"engin.h"
using namespace homer;
BoxCollider::BoxCollider(Entity* entity)
	:Component(entity)
{
	height = 20;
	width = 20;
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Start()
{
}

void BoxCollider::Destroy()
{
}

void BoxCollider::Draw()
{
    RectF frame = { m_Entity->GetX() + 6, m_Entity->GetY() + 6, width,height };
    Engin::Get()->Graphics().DrawRect(frame, Color::Green);
}