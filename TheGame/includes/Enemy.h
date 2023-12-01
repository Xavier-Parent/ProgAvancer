#include "Component.h"
#include "Animation.h"
#include "engin.h"
#include "TileMap.h"
#include "Observer.h"
#include "Action.h"

class Enemy: public Component, public IUpdatable, public Observer<Player_Action> {

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
	Enemy(Entity* entity);
	/// <summary>
	/// Destructor
	/// </summary>
	~Enemy();
	virtual void OnNotify(const Player_Action& value);
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
	/// Prepare the collider around the Character to know wich way to go
	/// </summary>
	/// <param name="name"></param>
	/// <param name="xOffset"></param>
	/// <param name="yOffset"></param>
	/// <returns></returns>
	Entity* CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset);
	/// <summary>
	/// Create the collider around the character
	/// </summary>
	void CreateColliders();
	/// <summary>
	/// Make the Enemy choose a direction he can go
	/// </summary>
	void ChooseRandomDirection();
	/// <summary>
	/// Detect the collision with the player Layer
	/// </summary>
	void CheckPlayerCollisions();
private:
	float enemySpeed;
	float normalSpeed;
	float weakenSpeed;
	float x, y;
	
	bool powerUp;
	bool goUp;
	bool goDown;
	bool goRight;
	bool goLeft;
	bool isWeak;


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