
#include "CollisionSystem.h"

bool CollisionSystem::Overlaps(
    const AABB& a, const AABB& b) const
{
    return a.minX < b.maxX &&
        a.maxX > b.minX &&
        a.minZ < b.maxZ &&
        a.maxZ > b.minZ;
}

bool CollisionSystem::IsPointInsideAABB(
    const Vector3& position, const AABB& box) const
{
    return position.x >= box.minX &&
        position.x <= box.maxX &&
        position.z >= box.minZ &&
        position.z <= box.maxZ;
}

bool CollisionSystem::MoveAndCollide(
    Vector3& position,
    const Vector3& movement,
    float halfWidth,
    float halfDepth,
    const AABB* obstacles,
    int obstacleCount) const
{
    if (halfWidth < 0.0f || halfDepth < 0.0f)
        return false;

    if (obstacleCount <= 0 || obstacles == nullptr)
    {
        position = position + movement;
        return false;
    }

    bool collided = false;

    // Resolve X first.
    Vector3 candidate = position;
    candidate.x += movement.x;

    AABB character{
        candidate.x - halfWidth,
        candidate.x + halfWidth,
        candidate.z - halfDepth,
        candidate.z + halfDepth
    };

    for (int i = 0; i < obstacleCount; ++i)
    {
        if (Overlaps(character, obstacles[i]))
        {
            collided = true;
            break;
        }
    }

    if (!collided)
        position.x = candidate.x;

    // Resolve Z independently to permit wall sliding.
    candidate = position;
    candidate.z += movement.z;

    character = {
        candidate.x - halfWidth,
        candidate.x + halfWidth,
        candidate.z - halfDepth,
        candidate.z + halfDepth
    };

    bool blockedZ = false;

    for (int i = 0; i < obstacleCount; ++i)
    {
        if (Overlaps(character, obstacles[i]))
        {
            blockedZ = true;
            break;
        }
    }

    if (!blockedZ)
        position.z = candidate.z;
    else
        collided = true;

    return collided;
}

