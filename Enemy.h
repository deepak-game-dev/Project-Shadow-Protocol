
#pragma once

#include "Vector3.h"
#include "CollisionSystem.h"
#include <vector>
class Player;
struct MovementData;
class MovementSystem;

enum class EnemyState
{
    Idle,
    Chase,
    Investigate,
    Attack
};

class Enemy
{
private:
    int health = 100;
    int damage;

    EnemyState state = EnemyState::Idle;

    float detectionRange = 8.0f;
    float attackRange = 1.5f;
    float attackCooldown = 1.0f;
    float attackTimer = 0.0f;

    float loseSightTime = 3.0f;
    float lostSightTimer = 0.0f;

    Vector3 lastKnownPosition;
    bool hasLastKnownPosition = false;

public:
    Enemy(int damage);

    void TakeDamage(int amount);
    int GetHealth() const;
    bool IsAlive() const;

    void Attack(Player& player);
    bool CanSeePlayer(
        const Vector3& enemyPosition,
        const Vector3& playerPosition,
        const std::vector<AABB>& obstacles) const;
    void UpdateAI(
        const MovementData& playerMovement,
        MovementData& enemyMovement,
        MovementSystem& movementSystem,
        Player& player,
        const std::vector<AABB>& obstacles,
        float deltaTime);

    EnemyState GetState() const;
};

