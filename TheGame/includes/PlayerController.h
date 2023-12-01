#include "Component.h"
#include "Animation.h"
#include "engin.h"
#include "TileMap.h"
#include "Subject.h"
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
	 /// <summary>
	 /// Function to check the collision of Wall to better control the player
	 /// </summary>
	 void CheckCollision();
	 /// <summary>
	 /// Function been call by the enemy when the player can kill them
	 /// </summary>
	 void EnemyCollisions();
	 /// <summary>
	 /// Prepare the collider around the Character to know wich way to go
	 /// </summary>
	 Entity* CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset);
	 /// <summary>
	 /// Create the collider around the character
	 /// </summary>
	 void CreateColliders();
	 /// <summary>
	 /// Function to be call when the player die
	 /// </summary>
	 void PlayerDead();
	 /// <summary>
	 /// Action to let know the enemy when they are weak
	 /// </summary>
	 Subject<bool> OnStateChanged;
	 /// <summary>
	 /// Action who give the Current score to the GameManager
	 /// </summary>
	 Subject<int> OnEatDot;
private:
	float playerSpeed;
	float powerUpTime;
	float timer;
	float x,y;

	bool powerUp;
	bool goUp;
	bool goDown;
	bool goRight;
	bool goLeft;
	bool beenCall;

	int collectable;
	int colIndex;
	int colX;
	int colY;
	int currentSoundIndex;

	size_t musicId;
	std::vector<size_t> soundIds;
	MovementState currentMovementState;

	Entity* upCollider = nullptr;
	Entity* downCollider = nullptr;
	Entity* leftCollider = nullptr;
	Entity* rightCollider = nullptr;
	Animation* animation = nullptr;
	Tilemap* tileMap = nullptr;
};