
#include "Enemy.h"
#include "Player.h"
#include "MovementData.h"
#include "MovementSystem.h"

Enemy::Enemy(int damage)
    : damage(damage)
{
}

void Enemy::TakeDamage(int amount)
{
    if (amount <= 0 || !IsAlive())
        return;

    health -= amount;

    if (health < 0)
        health = 0;
}

int Enemy::GetHealth() const
{
    return health;
}

bool Enemy::IsAlive() const
{
    return health > 0;
}

EnemyState Enemy::GetState() const
{
    return state;
}

void Enemy::Attack(Player& player)
{
    if (IsAlive() && player.IsAlive())
        player.TakeDamage(damage);
}

bool Enemy::CanSeePlayer(
    const Vector3& enemyPosition,
    const Vector3& playerPosition,
    const std::vector<AABB>& obstacles) const
{
    Vector3 difference = playerPosition - enemyPosition;
    difference.y = 0.0f;

    if (difference.Magnitude() > detectionRange)
        return false;

    constexpr int samples = 40;

    for (int i = 1; i < samples; ++i)
    {
        float t = static_cast<float>(i) / samples;
        float x = enemyPosition.x + difference.x * t;
        float z = enemyPosition.z + difference.z * t;

        for (const AABB& obstacle : obstacles)
        {
            if (x >= obstacle.minX && x <= obstacle.maxX &&
                z >= obstacle.minZ && z <= obstacle.maxZ)
            {
                return false;
            }
        }
    }

    return true;
}

void Enemy::UpdateAI(
    const MovementData& playerMovement,
    MovementData& enemyMovement,
    MovementSystem& movementSystem,
    Player& player,
    const std::vector<AABB>& obstacles,
    float deltaTime)
{
    if (!IsAlive() || !player.IsAlive())
    {
        enemyMovement.velocity = Vector3(0, 0, 0);
        state = EnemyState::Idle;
        return;
    }

    if (deltaTime < 0.0f)
        deltaTime = 0.0f;

    Vector3 difference =
        playerMovement.position - enemyMovement.position;

    difference.y = 0.0f;

    float distance = difference.Magnitude();

    bool canSeePlayer = CanSeePlayer(
        enemyMovement.position,
        playerMovement.position,
        obstacles);

    if (canSeePlayer)
    {
        lastKnownPosition = playerMovement.position;
        hasLastKnownPosition = true;
        lostSightTimer = loseSightTime;

        state = distance <= attackRange
            ? EnemyState::Attack
            : EnemyState::Chase;
    }
    else if (hasLastKnownPosition && lostSightTimer > 0.0f)
    {
        lostSightTimer -= deltaTime;
        state = EnemyState::Investigate;
    }
    else
    {
        state = EnemyState::Idle;
        hasLastKnownPosition = false;
    }

    Vector3 direction(0, 0, 0);

    if (state == EnemyState::Chase)
    {
        direction = difference.Normalized();
    }
    else if (state == EnemyState::Investigate)
    {
        Vector3 targetDifference =
            lastKnownPosition - enemyMovement.position;

        targetDifference.y = 0.0f;

        if (targetDifference.Magnitude() > 0.2f)
            direction = targetDifference.Normalized();
        else
            lostSightTimer = 0.0f;
    }

    if (state == EnemyState::Attack)
    {
        enemyMovement.velocity = Vector3(0, 0, 0);

        attackTimer -= deltaTime;

        if (attackTimer <= 0.0f)
        {
            Attack(player);
            attackTimer = attackCooldown;
        }
    }
    else
    {
        movementSystem.Update(
            enemyMovement, direction, deltaTime);
    }
}


