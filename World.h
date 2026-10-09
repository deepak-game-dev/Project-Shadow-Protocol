
#pragma once

#include "CollisionSystem.h"
#include <vector>

class World
{
private:
    std::vector<AABB> obstacles;

public:
    void AddObstacle(const AABB& obstacle);

    const std::vector<AABB>& GetObstacles() const;
};


