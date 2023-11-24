#include "TileMap.h"
#include "engin.h"
//#include <iostream>
#include <fstream>
#include <sstream>
using namespace homer;
Tilemap::Tilemap()
{
}

Tilemap::Tilemap(Entity* parent)
{
}

void Tilemap::Draw()
{
	//std::cout << "Draw";
	for (auto layer : m_Tilemap)
	{
		//std::cout << "layer Draw";
		for (int y = 0; y < m_Height/m_TileHeight + 1; y++)
		{
			for (int x = 0; x < m_Width/m_TileWidth; x++)
			{
				int _idx = layer.second[y][x];

				if (_idx >= 0)
				{
					//_idx -= 1;
					int _w = m_TileWidth * m_ScaleFactor;
					int _h = m_TileHeight * m_ScaleFactor;
					RectF _dst = {
						static_cast<float>(x * _w),
						static_cast<float>(y * _h),
						static_cast<float>(_w),
						static_cast<float>(_h)
					};
					Engin::Get()->Graphics().DrawTexture(
						m_TilesetId, m_Tileset[_idx],
						_dst, 0.0, { false, false }, Color::Red);
				}
			}
		}
	}
}
void Tilemap::Start()
{
}

void Tilemap::Destroy()
{
}

void Tilemap::Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH)
{
	auto& graphics = Engin::Get()->Graphics();
	m_TilesetId = graphics.LoadTexture(filename);
	m_TileWidth = tileW;
	m_TileHeight = tileH;
	m_Width = mapW;
	m_Height = mapH;
	int _w, _h;
	graphics.GetTextureSize(m_TilesetId, &_w, &_h);

	int _tilePerRow = _w / m_TileWidth;
	int _tilePerCol = _h / m_TileHeight;
	int _tileCount = _tilePerRow * _tilePerCol;

	for (int i = 0; i < _tileCount; i++)
	{
		int _ty = i / _tilePerRow;
		int _tx = i - _ty * _tilePerRow;

		RectI _tile = {
			_tx * m_TileWidth,
			_ty * m_TileHeight,
			m_TileWidth,
			m_TileHeight
		};

		m_Tileset.push_back(_tile);
	}
}

void Tilemap::AddLayer(const std::string& layer, TLayer tiles)
{
	if (m_Tilemap.count(layer) == 0)
	{
		m_Tilemap[layer] = tiles;
	}
}
void Tilemap::AddLayerFromCSV(const std::string& layerName, const std::string& filename)
{
	std::ifstream file(filename);
	TLayer layerData;
	std::string line;
	int rowIndex = 0; 
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::vector<int> row;
		std::string value;
		while (std::getline(iss, value, ','))
		{
			try {
				row.push_back(std::stoi(value));
			}
			catch (const std::invalid_argument& e) {
				// Handle conversion errors
				std::cerr << "Error converting string to integer: " << e.what() << std::endl;
			}
		}		
		if (!row.empty()) {
			layerData.push_back(row);
		}
		rowIndex++;
	}
	file.close();
	AddLayer(layerName, layerData);
}

TLayer Tilemap::GetLayer(const std::string& name)
{
	if (m_Tilemap.count(name) > 0)
	{
		return m_Tilemap[name];
	}

	return TLayer{};
}

int Clamp(int value, const int min, const int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}

	return value;
}

bool Tilemap::IsColliding(const std::string& layer, float x, float y, float w, float h, int* tileIndex)
{
	const int tLeftTile = Clamp(static_cast<int>(x / m_TileWidth), 0, m_Width);
	const int tRightTile = Clamp(static_cast<int>((x + w) / m_TileWidth), 0, m_Width);
	const int tTopTile = Clamp(static_cast<int>(y / m_TileHeight), 0, m_Height);
	const int tBottomTile = Clamp(static_cast<int>((y + h) / m_TileHeight), 0, m_Height);

	for (int i = tLeftTile; i <= tRightTile; i++)
	{
		for (int j = tTopTile; j <= tBottomTile; j++)
		{
			if (i < m_Width && j < m_Height)
			{
				if (m_Tilemap[layer][j][i] != 0)
				{
					*tileIndex = m_Tilemap[layer][j][i];
					return true;
				}
			}
		}
	}

	*tileIndex = -1;
	return false;
}
