#pragma once
#include <iostream>
#include "Atlas.h"

class Animation : Atlas{
	Animation();
	~Animation();
	void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	void Stop();
	void Play(const std::string& name, bool loop);
};