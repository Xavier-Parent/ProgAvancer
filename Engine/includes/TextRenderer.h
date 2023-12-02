#pragma once
#include "Component.h"
#include <iostream>
#include "engin.h"
class TextRenderer : public Component, public IDrawable
{
public:
	/// <summary>
	/// Constructor by default
	/// </summary>
	TextRenderer() = default;
	/// <summary>
	/// Constructor with Entity
	/// </summary>
	/// <param name="entity"></param>
	TextRenderer(Entity* entity);
	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~TextRenderer() = default;
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
	/// Initialisation of the text
	/// </summary>
	/// <param name="filename">The file string where the sprite is</param>
	/// <param name="w">The width of the sprite</param>
	/// <param name="h">Height of the sprite</param>
	void InitText(const std::string& fontfilename,const std::string& text, int fontSize, float x , float y);
private:
	std::string file;
	std::string currentText;
	size_t id;
	RectF square;
	float h;
	float w;
	float X;
	float Y;
	Color* color;
};