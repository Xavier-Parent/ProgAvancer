#include "Atlas.h"

using namespace homer;
Atlas::Atlas(Entity* entity)
	:SpriteRenderer(entity)
{
	frame = RectF();
	id = 0;
}

Atlas::~Atlas()
{
}

void Atlas::Draw()
{
	RectF square = RectF();
	square.x = m_Entity->GetX();
	square.y = m_Entity->GetY();
	square.h = frame.h * 10;
	square.w = frame.w * 10;
	//Engin::Get()->Graphics().DrawTexture(id, frame, square, 0, Flip(),  Color::Red);
}

void Atlas::AddFrame(const std::string& name, float x, float y, float w, float h)
{
	RectF rect{ x,y,h,w };
	frameMap[name] = rect;
}

void Atlas::SetFrame(const std::string& name)
{
	if (frameMap.count(name) > 0)
	{
		frame = frameMap[name];
	}
}

void Atlas::Init(const std::string& filename)
{
	id = Engin::Get()->Graphics().LoadTexture(filename);
}
