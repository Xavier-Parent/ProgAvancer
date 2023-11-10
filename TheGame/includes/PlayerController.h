#include "Component.h"
#include "Atlas.h"
#include"engin.h"
class PlayerController : public Component , public IUpdatable{

public:
	 PlayerController(Entity* entity);
	 ~PlayerController();


	 virtual void Start() override;
	 virtual void Update(float dt) override;
	 virtual void Destroy() override;


private:
	bool spawn = false;
	float x;
	float y;
	Atlas* atlas;
};