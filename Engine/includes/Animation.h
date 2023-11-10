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
	Animation() = default;
	Animation(Entity* entity);
	~Animation();
	void InitAnimation(const std::string& filename,int frameInRows, int frameInColumns, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	virtual void Update(float dt) override;
	virtual void Draw() override;
	void Stop();
	void Play(const std::string& name, bool loop);

private:
	size_t id;
	RectF frame;
	Clip currentClip;
	std::map<const std::string, Clip> clipMap;
	float delay;
	int index;
	int columns;
	int rows;
};