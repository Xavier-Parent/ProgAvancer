#include "Component.h"

class PlayerController : public Component , public IUpdatable{

public:
	 PlayerController();
	 ~PlayerController();

	 virtual void Update(float dt) override;


private:
	float x;
	float y;
};