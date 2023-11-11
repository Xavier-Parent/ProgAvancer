#pragma once

class IScene {
public:
	/// <summary>
	/// Destructor by default
	/// </summary>
	virtual ~IScene() = default;
	/// <summary>
	/// Function virtual pure who is gonna be Override for loading a scene
	/// </summary>
	virtual void Load() = 0;
};