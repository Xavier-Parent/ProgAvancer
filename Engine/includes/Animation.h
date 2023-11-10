#pragma once
#include <iostream>
#include "engin.h"
#include "SpriteRenderer.h"

class Animation : public SpriteRenderer, public IUpdatable
{
public:
	Animation() = default;
	Animation(Entity* entity);
	~Animation();
	void InitAnimation(const std::string& filename,int frameInRows, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	virtual void Update(float dt) override;
	void Stop();
	void Play(const std::string& name, bool loop);

private:
	size_t id;
	RectF square;
	float w;
	float h;
};