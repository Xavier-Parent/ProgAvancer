#pragma once
/// <summary>
/// Struct to communicate to the enemy
/// </summary>
struct Player_Action {
    bool hasPowerup;
    bool isDead;
};
/// <summary>
/// Struct for the action to communicate to the game manager
/// </summary>
struct Game_State {
    bool hasWon;
    bool HasLose;
    int _collectable;
};

