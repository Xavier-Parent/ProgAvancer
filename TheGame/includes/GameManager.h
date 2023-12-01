#pragma once
#include <Component.h>
#include <Observer.h>
#include <vector>
#include "TextRenderer.h"
class GameManager : public Component, public IUpdatable, public IDrawable, public Observer<int> {
public:
    /// <summary>
    /// Destructor by default
    /// </summary>
    virtual ~GameManager() = default;
    /// <summary>
    /// Contructor by default
    /// </summary>
    GameManager() = default;
    /// <summary>
    /// Game Manager Constructor
    /// </summary>
    /// <param name="parent"></param>
    GameManager(Entity* parent);
    /// <summary>
    /// The Action that is called by the player to the Game Manager
    /// </summary>
    /// <param name="value">The score of the player</param>
    virtual void OnNotify(const int& value);
    /// <summary>
    /// Function to draw
    /// </summary>
    virtual void Draw();
    /// <summary>
    /// Update Function
    /// </summary>
    /// <param name="dt">DeltaTime</param>
    virtual void Update(float dt) override;
    /// <summary>
    /// Start Function
    /// </summary>
    virtual void Start() override;
    /// <summary>
    /// Destroy Function
    /// </summary>
    virtual void Destroy() override;
private:
    TextRenderer* textRenderer;
    TextRenderer* textRenderer2;
    int score;
    std::vector<size_t> musicIds;
    int currentIndex;
};
