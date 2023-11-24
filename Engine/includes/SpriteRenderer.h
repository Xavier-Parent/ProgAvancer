#pragma once
#include "Component.h"
#include "engin.h"

class SpriteRenderer : public Component, public IDrawable
{
public:
	/// <summary>
	/// Constructor by default
	/// </summary>
	SpriteRenderer() = default;
	/// <summary>
	/// Constructor with Entity
	/// </summary>
	/// <param name="entity"></param>
	SpriteRenderer(Entity* entity);
	/// <summary>
	/// Destructor
	/// </summary>
	~SpriteRenderer();
	/// <summary>
	/// Function draw
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// Function Start
	/// </summary>
	virtual void Start() override;
	/// <summary>
	/// Function Destroy
	/// </summary>
	virtual void Destroy() override;
	/// <summary>
	/// Initialisation of the Sprite
	/// </summary>
	/// <param name="filename">The file string where the sprite is</param>
	/// <param name="w">The width of the sprite</param>
	/// <param name="h">Height of the sprite</param>
	void Init(const std::string& filename,float w ,float h);
	void InitText(const std::string& fontfilename, float fontSize);
private:
	size_t id;
	RectF square;
	float w;
	float h;
};