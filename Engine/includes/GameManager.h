#pragma once
#include <Component.h>
#include <Observer.h>
#include <vector>
#include "TextRenderer.h"
//#include ""
class GameManager : public Component, public IUpdatable, public IDrawable, public Observer<int> {
public:
    virtual ~GameManager() = default;
    GameManager() = default;
    GameManager(Entity* parent);
    virtual void OnNotify(const int& value);
    virtual void Draw();
    virtual void Update(float dt) override;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    TextRenderer* textRenderer;
    TextRenderer* textRenderer2;
    int score;
    std::vector<size_t> musicIds;
    int currentIndex;
};
