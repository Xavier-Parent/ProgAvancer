#include "PlayerController.h"
using namespace homer;

PlayerController::PlayerController(Entity* entity)
	:Component(entity)
{
	x = 348;
	y = 529;
	tileMap = Engin::Get()->World().Find("background")->GetComponent<Tilemap>();
	animation = m_Entity->GetComponent<Animation>();
	animation->AddClip("Right", 0, 4, 0.1f);
	animation->AddClip("Left", 14, 4, 0.1f);
	animation->AddClip("Up", 28, 4, 0.1f);
	animation->AddClip("Down", 42, 4, 0.1f);
	animation->AddClip("Dead", 4, 10, 0.3f);
	playerSpeed = 150;
	currentSoundIndex = 0;
	powerUp = false;
	goUp = false;
	goDown = false;
	goRight = false;
	goLeft = false;
	beenCall = false;
	playerDead = false;
	playerWin = false;
	end = false;
	colIndex = 0;
	colX = 0;
	colY = 0;
	collectable = 0;
	powerUpTime = 6;
	timer = 0;
	totalPoint = 0;
	musicId = 0;
	deadMusic = 0;
	deadSound = 0;
	currentMovementState = MovementState::IDLE;
}

PlayerController::~PlayerController()
{
}

void PlayerController::EnemyCollisions()
{
	Game_State _state;
	collectable += 200;
	_state._collectable = collectable;
	gameState.Invoke(_state);
}


void PlayerController::Start()
{
	CreateColliders();
	musicId = Engin::Get()->Audio().LoadMusic("assets/audio/power_pellet.wav");
	deadMusic = Engin::Get()->Audio().LoadMusic("assets/audio/Death_1.wav");
	deadSound = Engin::Get()->Audio().LoadSound("assets/audio/Death_2.wav");
	soundIds.push_back(Engin::Get()->Audio().LoadSound("assets/audio/munch_1.wav"));
	soundIds.push_back(Engin::Get()->Audio().LoadSound("assets/audio/munch_2.wav"));
	m_Entity->SetPosition(x, y);
}

void PlayerController::CheckCollision()
{
	if (tileMap->IsColliding("Wall", upCollider, &colIndex, &colX, &colY))
	{
		goUp = false;
	}
	else
	{
		goUp = true;
	}
	if (tileMap->IsColliding("Wall", downCollider, &colIndex, &colX, &colY) || tileMap->IsColliding("Door", downCollider, &colIndex, &colX, &colY))
	{
		goDown = false;
	}
	else
	{
		goDown = true;
	}
	if (tileMap->IsColliding("Wall", rightCollider, &colIndex, &colX, &colY))
	{
		goRight = false;
	}
	else
	{
		goRight = true;
	}
	if (tileMap->IsColliding("Wall", leftCollider, &colIndex, &colX, &colY))
	{
		goLeft = false;
	}
	else
	{
		goLeft = true;
	}
	EDirections dir = tileMap->IsColliding("Wall", m_Entity, &colIndex, &colX, &colY);

	if (tileMap->IsColliding("Collectable", m_Entity, &colIndex, &colX, &colY))
	{
		Game_State _state;
		collectable += 10;
		_state._collectable = collectable;
		gameState.Invoke(_state);
		totalPoint++;
		size_t currentSoundId = soundIds[currentSoundIndex];
		Engin::Get()->Audio().PlaySFX(currentSoundId);
		currentSoundIndex = (currentSoundIndex + 1) % soundIds.size();
	}
	if (tileMap->IsColliding("PowerUp", m_Entity, &colIndex, &colX, &colY))
	{
		totalPoint++;
		Engin::Get()->Audio().PlayMusic(musicId, -1);
		powerUp = true;
	}
	if (dir == RIGHT)
	{
		x = colX + 18.0f;
	}
	if (dir == LEFT)
	{
		x = colX - 26.0f;
	}
	if (dir == DOWN)
	{
		y = colY + 18.0f;
	}
	if (dir == UP)
	{
		y = colY - 26.0f;
	}
}
void PlayerController::PlayerDead()
{
	
	Game_State _loses;
	_loses._collectable = collectable;
	_loses.HasLose = true;
	_loses.hasWon = false;
	gameState.Invoke(_loses);

	Player_Action _action;
	playerDead = true;
	_action.isDead = playerDead;
	playerAction.Invoke(_action);
	playerSpeed = 0;
	animation->Play("Dead", false);
	Engin::Get()->Audio().StopMusic();
	Engin::Get()->Audio().PlayMusic(deadMusic, 0);
}

void PlayerController::Update(float dt)
{

	if (totalPoint >= 244 && playerWin == false)
	{
		Game_State _win;
		_win.hasWon = true;
		_win._collectable = collectable;
		gameState.Invoke(_win);
		playerSpeed = 0;
		playerWin = true;

		Player_Action _action;
		_action.isDead = true;
		playerAction.Invoke(_action);
	}
	if (playerDead == false && playerWin == false)
	{
		Player_Action act;
		act.hasPowerup = powerUp;
		x = m_Entity->GetX();
		y = m_Entity->GetY();
		if (powerUp == true)
		{
			if (beenCall == false)
			{

				act.hasPowerup = powerUp;
				playerAction.Invoke(act);
				beenCall = true;
			}
			animation->speed = 3;
			timer += dt;
			if (timer >= powerUpTime)
			{
				powerUp = false;
				Engin::Get()->Audio().StopMusic();
				beenCall = false;
				act.hasPowerup = powerUp;
				playerAction.Invoke(act);
				timer = 0;
			}
		}
		else
		{
			animation->speed = 1;
		}
		CheckCollision();
		MovementState newMovementState = currentMovementState;
		if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_D) && goRight == true) {
			newMovementState = MovementState::MOVE_RIGHT;
		}
		if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_A) && goLeft == true) {
			newMovementState = MovementState::MOVE_LEFT;
		}
		if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_W) && goUp == true) {
			newMovementState = MovementState::MOVE_UP;
		}
		if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_S) && goDown == true) {
			newMovementState = MovementState::MOVE_DOWN;
		}

		switch (currentMovementState) {
		case MovementState::MOVE_RIGHT:
			x += playerSpeed * dt;
			animation->Play("Right", true);
			if (x > 712) {
				x = -36;
			}
			break;
		case MovementState::MOVE_LEFT:
			x -= playerSpeed * dt;
			animation->Play("Left", true);
			if (x < -36) {
				x = 712;
			}
			break;
		case MovementState::MOVE_UP:
			y -= playerSpeed * dt;
			animation->Play("Up", true);
			break;
		case MovementState::MOVE_DOWN:
			y += playerSpeed * dt;
			animation->Play("Down", true);
			break;
		case MovementState::IDLE:
			break;
		default:
			break;
		}

		EDirections collisionDirection = tileMap->IsColliding("Wall", m_Entity, &colIndex, &colX, &colY);
		if (collisionDirection != EDirections::NONE) {
			currentMovementState = MovementState::IDLE;
		}
		else {
			currentMovementState = newMovementState;
		}

		m_Entity->SetPosition(x, y);
		upCollider->SetPosition(m_Entity->GetX(), m_Entity->GetY() - 16);
		downCollider->SetPosition(m_Entity->GetX(), m_Entity->GetY() + 16);
		rightCollider->SetPosition(m_Entity->GetX() + 16, m_Entity->GetY());
		leftCollider->SetPosition(m_Entity->GetX() - 16, m_Entity->GetY());
	}
	if(playerDead == true)
	{
		timer += dt;
		if (timer >= 3)
		{
			Engin::Get()->Audio().PlaySFX(deadSound, 0);
			m_Entity->SetPosition(1000,1000);
			playerDead = false;
		}
	}
}


Entity* PlayerController::CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset) {
	Entity* collider = Engin::Get()->World().Create(name);
	collider->SetPosition(m_Entity->GetX() + xOffset, m_Entity->GetY() + yOffset);
	return collider;
}

void PlayerController::CreateColliders() {
	const int offset = 16;
	upCollider = CreateAndSetupCollider("upCollider", 0, -offset);
	downCollider = CreateAndSetupCollider("downCollider", 0, offset);
	rightCollider = CreateAndSetupCollider("rightCollider", offset, 0);
	leftCollider = CreateAndSetupCollider("leftCollider", -offset, 0);
}


void PlayerController::Destroy()
{
}
