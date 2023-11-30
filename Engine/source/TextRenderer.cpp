#include "TextRenderer.h"

using namespace homer;
TextRenderer::TextRenderer(Entity* entity)
	:Component(entity)
{
	h = 0;
	w = 0;
	id = 0;
	square = RectF();
}

TextRenderer::~TextRenderer()
{
}
void TextRenderer::Draw()
{
	square.x = m_Entity->GetX();
	square.y = m_Entity->GetY();
	square.h = h;
	square.w = w;
	Engin::Get()->Graphics().DrawString(currentText, id, X, Y, Color::Blue);
}

void TextRenderer::Start()
{
}

void TextRenderer::Destroy()
{
}

void TextRenderer::InitText(const std::string& fontfilename,const std::string& text, float fontSize, float x,float y)
{
	X = x;
	Y = y;
	currentText = text;
	id = homer::Engin::Get()->Graphics().LoadFont(fontfilename, fontSize);
}
