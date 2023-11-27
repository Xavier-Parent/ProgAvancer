#include "Component.h"
#include "Animation.h"
#include "engin.h"
#include "TileMap.h"
class PlayerController : public Component , public IUpdatable{

	enum class MovementState {
		IDLE,
		MOVE_RIGHT,
		MOVE_LEFT,
		MOVE_UP,
		MOVE_DOWN
	};

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
	 void CheckCollision();
	 Entity* CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset);
	 void CreateColliders();
private:
	bool powerUp;
	float playerSpeed;
	float x,y;
	bool goUp;
	bool goDown;
	bool goRight;
	bool goLeft;

	int colIndex;
	int colX;
	int colY;

	size_t musicId;
	std::vector<size_t> soundIds;
	int currentSoundIndex;
	MovementState currentMovementState;

	Entity* upCollider = nullptr;
	Entity* downCollider = nullptr;
	Entity* leftCollider = nullptr;
	Entity* rightCollider = nullptr;
	Animation* animation = nullptr;
	Tilemap* tileMap = nullptr;
};