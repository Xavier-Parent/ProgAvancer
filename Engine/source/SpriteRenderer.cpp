#include "SpriteRenderer.h"


using namespace homer;

SpriteRenderer::SpriteRenderer(Entity* entity)
	:Component(entity)
{
	h = 0;
	w = 0;
	id = 0;
	square = RectF();
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Draw()
{
	square.x = m_Entity->GetX();
	square.y = m_Entity->GetY();
	square.h = h;
	square.w = w;
	Engin::Get()->Graphics().DrawTexture(id, square, Color::Red);
}

void SpriteRenderer::Start()
{
}

void SpriteRenderer::Destroy()
{
}

void SpriteRenderer::Init(const std::string& filename,float H , float W)
{
	id = Engin::Get()->Graphics().LoadTexture(filename);
	w = W;
	h = H;
}