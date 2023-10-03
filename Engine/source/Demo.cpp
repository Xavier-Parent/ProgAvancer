// Script pour la generation de tilemap; 



/*
#include <SDL_image.h>
#include "RectI.h"
#include <iostream>

typedef std::vector<rectI> TTileset;
typedef std::vector<std::vector<int>> TLayer;
typedef std::map<std::string, TLayer> TTilemap;

TTileset m_Tileset;
TTIlemap m_TileMap;
SDL_Texture m_TileSetTexture;

void Demo::AddLayer(const std::string&)

void Demo::Load(const std::string& image, int tileW, int tileH, int col, int count)
{
	m_TileSetTexture = IMG_LoadTexture(m_Graphics, image.c_str());
	if (m_TileSetTexture)
	{
		for (int i = 0; i < count; i++)
		{
			int _y = i / col;
			int _x = i - _y * col;

			RectI _tile(_x * tileW, _y * tileH, tileW, tileH);

			m_Tileset.push_back(_tile);
		}
	}
}
void Demo::RenderFrame()
{
	int testIdx = 32
}

void Demo::UpdateLogic()
{

}

void Demo::Shutdown()
{

}
*/