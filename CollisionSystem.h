
#pragma once

#include "Vector3.h"

struct AABB
{
    float minX;
    float maxX;
    float minZ;
    float maxZ;
};

class CollisionSystem
{
public:
    bool Overlaps(const AABB& a, const AABB& b) const;

    bool IsPointInsideAABB(
        const Vector3& position,
        const AABB& box) const;

    bool MoveAndCollide(
        Vector3& position,
        const Vector3& movement,
        float halfWidth,
        float halfDepth,
        const AABB* obstacles,
        int obstacleCount) const;
};


