#pragma once
#include <iostream>
#include "engin.h"
#include "SpriteRenderer.h"
#include <map>
class Animation : public SpriteRenderer, public IUpdatable
{
	struct Clip {
		int _start;
		int _count;
	};


public:
	/// <summary>
	/// Constructor by default
	/// </summary>
	Animation() = default;
	/// <summary>
	/// Constructor with Entity
	/// </summary>
	/// <param name="entity">Entity</param>
	Animation(Entity* entity);
	/// <summary>
	/// Destructor by default
	/// </summary>
	~Animation();
	/// <summary>
	/// Function to initialise Animation
	/// </summary>
	/// <param name="filename">The string of the file where the sprite sheet is</param>
	/// <param name="frameInRows">Number of frame in a row in the sprite sheets</param>
	/// <param name="frameInColumns">Number of frame in a columns in the sprite sheet</param>
	/// <param name="frameWidth">Width of a single frame</param>
	/// <param name="frameHeight">Height of a single frame</param>
	void InitAnimation(const std::string& filename, int frameInRows, int frameInColumns, int frameWidth, int frameHeight);
	/// <summary>
	/// Function to AddClip in a Map
	/// </summary>
	/// <param name="name">Name of the clip</param>
	/// <param name="start">Frame where the animation will start in the sprite sheet</param>
	/// <param name="count">Number of frame who is gonna play in the clip</param>
	/// <param name="delay">Delay between each sprite in the clip</param>
	void AddClip(const std::string& name, int start, int count, float delay);
	/// <summary>
	/// Function to update
	/// </summary>
	/// <param name="dt">the delta time</param>
	virtual void Update(float dt) override;
	/// <summary>
	/// Function Draw
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// Fonction to stop the animation
	/// </summary>
	void Stop();
	/// <summary>
	/// Function to play a clip
	/// </summary>
	/// <param name="name">the name of the clip</param>
	/// <param name="loop">Boolean to loop the clip</param>
	void Play(const std::string& name, bool loop);

private:
	size_t id;
	RectF frame;
	Clip currentClip;
	std::map<const std::string, Clip> clipMap;
	float delay;
	float timer;
	int index;
	int columns;
	int rows;
	bool loop;
};