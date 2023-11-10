#pragma once
#include "SpriteRenderer.h"
#include <iostream>
#include "engin.h"
#include <map>
class Atlas : public SpriteRenderer{

public:
	Atlas() = default;
	Atlas(Entity* entity);
	~Atlas();

	virtual void Draw() override;
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);
	void Init(const std::string& filename);
private:
	RectF frame;
	size_t id;
	std::map<const std::string, RectF> frameMap;
};