#pragma once
#include <ICollider.h>
#include <map>
#include <vector>

class Collision : public ICollider
{
public:
    /// <summary>
    /// Constructor of Collision
    /// </summary>
    Collision();
    /// <summary>
    /// Destructor by default
    /// </summary>
    virtual ~Collision() = default;
    /// <summary>
    /// Function to detect collision between a point and a circle
    /// </summary>
    /// <param name="px">point X</param>
    /// <param name="py">Point Y</param>
    /// <param name="cx">Circle X</param>
    /// <param name="cy">Circle Y</param>
    /// <param name="cr">Circle Rayon</param>
    /// <returns>Return true if they collide</returns>
    virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) override;
    /// <summary>
    /// Check collision between circle
    /// </summary>
    /// <param name="c1x">Circle 1 X</param>
    /// <param name="c1y">Circle 1 Y</param>
    /// <param name="c1r">C 1 Rayon</param>
    /// <param name="c2x">Circle 2 X</param>
    /// <param name="c2y">Circle 2 Y</param>
    /// <param name="c2r">Circle 2 Rayon</param>
    /// <returns>Return true if they collide</returns>
    virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) override;
    /// <summary>
    /// Check Collision beween point and Rectangle
    /// </summary>
    /// <param name="px">Point X</param>
    /// <param name="py">Point Y</param>
    /// <param name="rx">Rectangle X</param>
    /// <param name="ry">Rectangle Y</param>
    /// <param name="rw">Rectangle Width</param>
    /// <param name="rh">Rectangle Heigh</param>
    /// <returns>Return if collide</returns>
    virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) override;
    /// <summary>
    /// Check Collision between 2 Rectangle
    /// </summary>
    /// <param name="r1x">Rectangle 1 X</param>
    /// <param name="r1y">Rectangle 1 Y</param>
    /// <param name="r1w">Rectangle 1 Width</param>
    /// <param name="r1h">Rectangle 1 Height</param>
    /// <param name="r2x">Rectangle 2 X</param>
    /// <param name="r2y">Rectangle 2 Y</param>
    /// <param name="r2w">Rectangle 2 Width</param>
    /// <param name="r2h">Rectangle 2 Height</param>
    /// <returns>Return true if they collide</returns>
    virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) override;
    /// <summary>
    /// Check Collision betwenn Rectangle and Circle
    /// </summary>
    /// <param name="rx">Rectangle X</param>
    /// <param name="ry">Rectangle Y</param>
    /// <param name="rw">Rectangle Width</param>
    /// <param name="rh">Rectangle Height</param>
    /// <param name="cx">Circle X</param>
    /// <param name="cy">Circle Y</param>
    /// <param name="cr">Circle Rayon</param>
    /// <returns>Return true if they collide</returns>
    virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) override;
    /// <summary>
    /// Function to add a layer to an Entity
    /// </summary>
    /// <param name="layerName">The name of the layer</param>
    /// <param name="entity">The Entity who will have the Layer</param>
    virtual void AddToLayer(const std::string& layerName, Entity* entity) override;
    /// <summary>
    /// Function to detect when a player have  a Collision with an entity layer
    /// </summary>
    /// <param name="entity">The first entity who collide</param>
    /// <param name="layerName">The layer that the first Entity collide</param>
    /// <param name="other">The Entity who as been Collide</param>
    /// <returns>Return true if collide</returns>
    virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other) override;
    /// <summary>
    /// Remove the layer of an enemy
    /// </summary>
    /// <param name="entity"></param>
    virtual void Remove(Entity* entity) override;
    /// <summary>
    /// Clear the collider
    /// </summary>
    virtual void Clear() override;

private:
    std::map<std::string, std::vector<Entity*>> m_Layers;
};