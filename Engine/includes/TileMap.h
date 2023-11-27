#pragma once
#include <vector>
#include <map>
#include <string>
#include <Component.h>
#include <IGraphics.h>

typedef std::vector<std::vector<int>> TLayer;
typedef std::map<std::string, TLayer> TTilemap;
typedef std::vector<RectI> TTileset;


enum EDirections
{
    NONE,
    RIGHT,
    UP,
    LEFT,
    DOWN
};

class Tilemap : public Component, public IDrawable
{
public:
    virtual ~Tilemap() = default;
    Tilemap();
    Tilemap(Entity* parent);
    virtual void Draw() override;
    virtual void Start() override;
    virtual void Destroy() override;
    void Tilemap::AddLayerFromCSV(const std::string& layerName, const std::string& filename);
    void Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH);
    void AddLayer(const std::string& layer, TLayer tiles);
    TLayer GetLayer(const std::string& name);
    EDirections IsColliding(const std::string& layer, Entity* entity, int* tileIndex, int* tileX, int* tileY);

private:
    TTilemap m_Tilemap;
    int m_Width = 0;
    int m_Height = 0;
    size_t m_TilesetId = 0;
    int m_TileWidth = 0;
    int m_TileHeight = 0;
    TTileset m_Tileset;
    float m_ScaleFactor = 3;
};