#include "BoxCollider.h"
//#include"engin.h"
using namespace homer;
BoxCollider::BoxCollider(Entity* entity)
	:Component(entity)
{
	height = 20;
	width = 20;
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Start()
{
}

void BoxCollider::Destroy()
{
}

void BoxCollider::Draw()
{
    RectF frame = { m_Entity->GetX() + 6, m_Entity->GetY() + 6, width,height };
    Engin::Get()->Graphics().DrawRect(frame, Color::Green);
}

bool BoxCollider::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
    float vecX = px - cx;
    float vecY = py - cy;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= cr;
}
bool BoxCollider::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h)
{
    return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x &&
        r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
}

bool BoxCollider::CheckPointRect(float px, float py, float rx, float ry, float rw, float rh)
{
    return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}

bool BoxCollider::CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr)
{
    if (CheckPointRect(cx, cy, rx, ry, rw, rh))
    {
        return true;
    }

    float tx = cx;
    float ty = cy;

    if (tx < rx) tx = rx;
    if (tx > rx + rw) tx = rx + rw;
    if (ty < ry) ty = ry;
    if (ty > ry + rh) ty = ry + rh;

    return CheckPointCircle(tx, ty, cx, cy, cr);
}

void BoxCollider::AddToLayer(const std::string& layerName, Entity* entity)
{
    if (m_Layers.count(layerName) == 0)
    {
        m_Layers.emplace(layerName, std::vector<Entity*>());
    }

    m_Layers[layerName].push_back(entity);
}

bool BoxCollider::CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other)
{
    *other = nullptr;
    if (m_Layers.count(layerName) > 0)
    {
        float r1x, r1y, r1w, r1h;
        float r2x, r2y, r2w, r2h;

        entity->GetPosition(&r1x, &r1y);
        entity->GetSize(&r1w, &r1h);

        for (Entity* e : m_Layers[layerName])
        {
            e->GetPosition(&r2x, &r2y);
            e->GetSize(&r2w, &r2h);

            if (CheckRects(r1x, r1y, r1w, r1h, r2x, r2y, r2w, r2h))
            {
                *other = e;
                return true;
            }
        }
    }

    return false;
}
