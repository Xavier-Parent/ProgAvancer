#pragma once
#include "SpriteRenderer.h"
#include <iostream>
class Atlas : SpriteRenderer {

public:
	Atlas();
	~Atlas();

	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);

private:
};