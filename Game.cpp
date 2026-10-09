
#include "Game.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

Game::Game()
    : player(10), enemy(20)
{
    movementData.position = Vector3(0.0f, 0.0f, 0.0f);
    movementData.velocity = Vector3(0.0f, 0.0f, 0.0f);

    enemyMovementData.position = Vector3(6.0f, 0.0f, 0.0f);
    enemyMovementData.velocity = Vector3(0.0f, 0.0f, 0.0f);
    enemyMovementData.speed = 3.0f;
    enemyMovementData.acceleration = 8.0f;
}


void Game::InitializeAll()
{
    world.AddObstacle(
        AABB{ 2.0f, 4.0f, -2.0f, 2.0f });

    world.AddObstacle(
        AABB{ -4.0f, -2.0f, 1.0f, 5.0f });


    world.AddObstacle(
        AABB{ 4.0f, 6.0f, 5.0f, 7.0f });

    std::cout << "Game initialized!\n";
    std::cout << "WASD = Move | F = Attack | E = Interact | ESC = Quit\n";
    std::cout << "Collect the research drive and reach extraction.\n";
    std::cout << "Starting in 2 seconds...\n";

    std::this_thread::sleep_for(
        std::chrono::seconds(2));
}


void Game::Run()
{
    InitializeAll();

    using Clock = std::chrono::steady_clock;
    auto previousTime = Clock::now();

    while (player.IsAlive() &&
        !missionComplete &&
        (GetAsyncKeyState(VK_ESCAPE) & 0x8000) == 0)
    {
        const auto currentTime = Clock::now();

        float deltaTime =
            std::chrono::duration<float>(
                currentTime - previousTime).count();

        previousTime = currentTime;

     
        if (deltaTime > 0.05f)
            deltaTime = 0.05f;

        inputSystem.Update();

        UpdateAll(deltaTime);
        Renderall();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(16));
    }

    if (missionComplete)
        std::cout << "\n\nMISSION COMPLETE!\n";
    else if (!player.IsAlive())
        std::cout << "\n\nMISSION FAILED - PLAYER DOWN!\n";
    else
        std::cout << "\n\nGame stopped.\n";
}

void Game::UpdateAll(float deltaTime)
{


    Vector3 direction(0.0f, 0.0f, 0.0f);

    if (inputSystem.IsHeld(Action::MoveForward))
        direction.z += 1.0f;

    if (inputSystem.IsHeld(Action::MoveBackward))
        direction.z -= 1.0f;

    if (inputSystem.IsHeld(Action::MoveRight))
        direction.x += 1.0f;

    if (inputSystem.IsHeld(Action::MoveLeft))
        direction.x -= 1.0f;

  
    Vector3 previousPlayerPosition = movementData.position;

    movementSystem.Update(
        movementData, direction, deltaTime);

    Vector3 desiredPlayerPosition = movementData.position;

    movementData.position = previousPlayerPosition;

    Vector3 intendedPlayerMovement(
        desiredPlayerPosition.x - previousPlayerPosition.x,
        0.0f,
        desiredPlayerPosition.z - previousPlayerPosition.z);


    const auto& obstacles = world.GetObstacles();

    collisionSystem.MoveAndCollide(
        movementData.position,
        intendedPlayerMovement,
        0.35f,
        0.35f,
        obstacles.data(),
        static_cast<int>(obstacles.size()));


    if (movementData.position.x != desiredPlayerPosition.x)
        movementData.velocity.x = 0.0f;

    if (movementData.position.z != desiredPlayerPosition.z)
        movementData.velocity.z = 0.0f;


    if (inputSystem.IsPressed(Action::Attack))
    {
        if (player.IsAlive() && enemy.IsAlive())
            player.Attack(enemy);
    }

  

    Vector3 previousEnemyPosition = enemyMovementData.position;

    enemy.UpdateAI(
        movementData,
        enemyMovementData,
        movementSystem,
        player,
        obstacles,
        deltaTime);


    Vector3 desiredEnemyPosition = enemyMovementData.position;

    enemyMovementData.position = previousEnemyPosition;

    Vector3 intendedEnemyMovement(
        desiredEnemyPosition.x - previousEnemyPosition.x,
        0.0f,
        desiredEnemyPosition.z - previousEnemyPosition.z);


    collisionSystem.MoveAndCollide(
        enemyMovementData.position,
        intendedEnemyMovement,
        0.35f,
        0.35f,
        obstacles.data(),
        static_cast<int>(obstacles.size()));


    if (enemyMovementData.position.x != desiredEnemyPosition.x)
        enemyMovementData.velocity.x = 0.0f;

    if (enemyMovementData.position.z != desiredEnemyPosition.z)
        enemyMovementData.velocity.z = 0.0f;

    // -------------------------
    // 5. Research drive interaction
    // -------------------------

    if (inputSystem.IsPressed(Action::Interact))
    {
        if (!researchDrive.collected)
        {
            if (interactionSystem.TryInteract(
                researchDrive,
                movementData.position,
                1.5f))
            {
                std::cout << "\nResearch drive collected!\n";
            }
            else
            {
                std::cout << "\nMove closer to the research drive!\n";
            }
        }
        else
        {

            Vector3 difference =
                extractionPosition - movementData.position;

            difference.y = 0.0f;

            if (player.IsAlive() &&
                difference.Magnitude() <= extractionRange)
            {
                missionComplete = true;
            }
            else
            {
                std::cout << "\nReach the extraction zone!\n";
            }
        }
    }
}

void Game::Renderall()
{
    Vector3 extractionDifference =
        extractionPosition - movementData.position;

    extractionDifference.y = 0.0f;

    std::cout
        << "\rPlayer HP: " << player.GetHealth()
        << " | Enemy HP: " << enemy.GetHealth()
        << " | Player: ("
        << movementData.position.x << ", "
        << movementData.position.z << ")"
        << " | Enemy: ("
        << enemyMovementData.position.x << ", "
        << enemyMovementData.position.z << ")"
        << " | Drive: "
        << (researchDrive.collected ? "Collected" : "Not collected");

    if (researchDrive.collected)
    {
        if (extractionDifference.Magnitude() <= extractionRange)
            std::cout << " | Press E to extract!";
        else
            std::cout << " | Find extraction at (0, -4)";
    }

    std::cout << "          " << std::flush;
}

