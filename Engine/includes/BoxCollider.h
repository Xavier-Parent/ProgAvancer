#include "Component.h"
#include <math.h>
#include "engin.h"
class BoxCollider : public Component, public IDrawable
{
public:
	BoxCollider() = default;
	BoxCollider(Entity* entity);
	~BoxCollider();

	void GetSize(float* w, float* h)
	{
		*w = width;
		*h = height;
	}
	virtual void Start() override;
	virtual void Destroy() override;
	float GetH() { return height; }
	float GetW() { return width; }
	virtual void Draw() override;
	bool CheckPointCircle(float px, float py, float cx, float cy, float cr);
	bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h);
	bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh);
	bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr);

	void AddToLayer(const std::string& layerName, Entity* entity);
	bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other);

private:
	float height;
	float width;
	std::map<std::string, std::vector<Entity*>> m_Layers;
};