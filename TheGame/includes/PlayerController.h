#include "Component.h"
#include "Atlas.h"
#include "Animation.h"
#include "engin.h"
#include "TileMap.h"
class PlayerController : public Component , public IUpdatable{

public:
	 /// <summary>
	 /// Player Controller Contructor
	 /// </summary>
	 /// <param name="dt">The Entity</param>
	 PlayerController(Entity* entity);
	 /// <summary>
	 /// Destructor
	 /// </summary>
	 ~PlayerController();

	 /// <summary>
	 /// Function Start
	 /// </summary>
	 virtual void Start() override;
	 /// <summary>
	 /// Function to Update
	 /// </summary>
	 virtual void Update(float dt) override;
	 /// <summary>
	 /// Function to Destroy
	 /// </summary>
	 virtual void Destroy() override;

private:
	bool spawn = false;
	bool hit = false;
	float speedx;
	float speedy;
	float x;
	float y;
	Atlas* atlas = nullptr;
	Animation* animation = nullptr;
	Tilemap* tileMap = nullptr;
};