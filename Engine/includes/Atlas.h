#pragma once
#include "SpriteRenderer.h"
#include <iostream>
#include "engin.h"
#include <map>
class Atlas : public SpriteRenderer{

public:
	/// <summary>
	/// Constructor by Default
	/// </summary>
	Atlas() = default;
	/// <summary>
	/// Constructor With Entity
	/// </summary>
	/// <param name="entity">The Entity</param>
	Atlas(Entity* entity);
	/// <summary>
	/// Destructor
	/// </summary>
	~Atlas();
	/// <summary>
	/// Function Draw
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// Function to add frame to he Map
	/// </summary>
	/// <param name="name">Name of the Frame</param>
	/// <param name="x">Position of the Frame in the Horizontal Axis</param>
	/// <param name="y">Position of the frame on the Vertical Axis</param>
	/// <param name="w">Width of the frame</param>
	/// <param name="h">Height of the frame</param>
	void AddFrame(const std::string& name, float x, float y, float w, float h);
	/// <summary>
	/// Set the image to see in the scene
	/// </summary>
	/// <param name="name">Name of the image</param>
	void SetFrame(const std::string& name);
	/// <summary>
	/// Function to initialise a new image
	/// </summary>
	/// <param name="filename">The file string of the place where the sprite is</param>
	void Init(const std::string& filename);
private:
	RectF frame;
	size_t id;
	std::map<const std::string, RectF> frameMap;
};