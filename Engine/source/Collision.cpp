#include "Collision.h"
#include <math.h>
#include <Entity.h>

Collision::Collision()
{
}

bool Collision::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
    float vecX = px - cx;
    float vecY = py - cy;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= cr;
}

bool Collision::CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r)
{
    float vecX = c1x - c2x;
    float vecY = c1y - c2y;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= (c1r + c2r);
}

bool Collision::CheckPointRect(float px, float py, float rx, float ry, float rw, float rh)
{
    return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}

bool Collision::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h)
{
    return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x &&
        r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
}

bool Collision::CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr)
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

void Collision::AddToLayer(const std::string& layerName, Entity* entity)
{
    std::cout << "VaginPoilu";
    if (m_Layers.count(layerName) == 0)
    {
        m_Layers.emplace(layerName, std::vector<Entity*>());
    }

    m_Layers[layerName].push_back(entity);
}

bool Collision::CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other)
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

void Collision::Remove(Entity* entity)
{
    for (auto layer : m_Layers)
    {
        std::vector<Entity*>::iterator it = layer.second.begin();
        while (it != layer.second.end())
        {
            if (*it == entity)
            {
                layer.second.erase(it);
                return;
            }

            it++;
        }
    }
}
