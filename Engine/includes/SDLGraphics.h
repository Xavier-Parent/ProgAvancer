#pragma once
#include "IGraphics.h"
#include "SDL_image.h"
#include <map>
class SDLGraphics : public IGraphics
{
	virtual void DrawLine(int x0, int y0, int x1, int y1) override;
private:
	std::map<size_t, SDL_Texture> hashMap;
};

