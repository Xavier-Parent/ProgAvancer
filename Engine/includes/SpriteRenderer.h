#pragma once
#include "Component.h"
#include "engin.h"

class SpriteRenderer : public Component, public IDrawable
{
public:
	SpriteRenderer() = default;
	SpriteRenderer(Entity* entity);
	~SpriteRenderer();

	virtual void Draw() override;
	virtual void Start() override;
	virtual void Destroy() override;
	void Init(const std::string& filename,float w ,float h);
private:
	size_t id;
	RectF square;
	float w;
	float h;
};