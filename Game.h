
#pragma once

#include "Player.h"
#include "Enemy.h"
#include "InputSystem.h"
#include "MovementData.h"
#include "MovementSystem.h"
#include "World.h"
#include "CollisionSystem.h"
#include "InteractionSystem.h"
class Game
{
private:
    Player player;
    Enemy enemy;

    InputSystem inputSystem;
    MovementData movementData;
    MovementSystem movementSystem;
    CollisionSystem collisionSystem;
    AABB wall{ 2.0f, 4.0f, -2.0f, 2.0f };
    MovementData enemyMovementData;
    InteractionSystem interactionSystem;
    World world;

    MissionObject researchDrive{
        Vector3(0.0f, 0.0f, 4.0f),
        false
    };

    bool missionComplete = false;

    Vector3 extractionPosition{ 0.0f, 0.0f, -4.0f };
    float extractionRange = 1.5f;

public:
    Game();

    void InitializeAll();
    void Run();
    void UpdateAll(float deltaTime);
    void Renderall();
};
