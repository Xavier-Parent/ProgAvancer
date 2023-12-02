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
    /// <summary>
    /// Destructor by default
    /// </summary>
    virtual ~Tilemap() = default;
    /// <summary>
    /// Constructor
    /// </summary>
    Tilemap();
    /// <summary>
    /// Real Constructor
    /// </summary>
    /// <param name="parent"></param>
    Tilemap(Entity* parent);
    /// <summary>
    /// Draw Function
    /// </summary>
    virtual void Draw() override;
    /// <summary>
    /// Start Function
    /// </summary>
    virtual void Start() override;
    /// <summary>
    /// Destroy Function
    /// </summary>
    virtual void Destroy() override;
    /// <summary>
    /// Function To add a layer using CSV to the tilemap
    /// </summary>
    /// <param name="layerName">The name of the layer</param>
    /// <param name="filename">The File where is the CSV</param>
    void Tilemap::AddLayerFromCSV(const std::string& layerName, const std::string& filename);
    /// <summary>
    /// Load the Map
    /// </summary>
    /// <param name="filename">File where the tilemap is</param>
    /// <param name="mapW">Map width</param>
    /// <param name="mapH">Map Height</param>
    /// <param name="tileW">Tile Width</param>
    /// <param name="tileH">Tile Height</param>
    void Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH);
    /// <summary>
    /// When the CSV add now we can add the layer
    /// </summary>
    /// <param name="layer">name of the layer</param>
    /// <param name="tiles">Data of the tile</param>
    void AddLayer(const std::string& layer, TLayer tiles);
    /// <summary>
    /// Function to get the layer
    /// </summary>
    /// <param name="name">Name of the layer</param>
    /// <returns>the good data</returns>
    TLayer GetLayer(const std::string& name);
    /// <summary>
    /// Function to know wich direction the entity is colliding with the map
    /// </summary>
    /// <param name="layer">layer of the tile map is collide</param>
    /// <param name="entity">the entity who collide with the Map</param>
    /// <param name="tileIndex">index to store the tile</param>
    /// <param name="tileX">index to store the x of the tile</param>
    /// <param name="tileY">index to store the y of the tile</param>
    /// <returns>the direction in enum</returns>
    EDirections IsColliding(const std::string& layer, Entity* entity, int* tileIndex, int* tileX, int* tileY);

private:
    TTilemap m_Tilemap;
    int m_Width = 0;
    int m_Height = 0;
    size_t m_TilesetId = 0;
    int m_TileWidth = 0;
    int m_TileHeight = 0;
    TTileset m_Tileset;
    int m_ScaleFactor = 3;
};