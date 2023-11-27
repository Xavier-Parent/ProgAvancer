#include "Component.h"
#include "Animation.h"
#include "engin.h"
#include "TileMap.h"
#include "Observer.h"
class Enemy : public Component, public IUpdatable, public Observer<bool> {

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
	virtual void OnNotify(const bool& value);
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
	void ChooseRandomDirection();
private:
	bool powerUp;
	float enemySpeed;
	float normalSpeed;
	float weakenSpeed;
	float x, y;
	bool goUp;
	bool goDown;
	bool goRight;
	bool goLeft;

	bool isWeak;

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