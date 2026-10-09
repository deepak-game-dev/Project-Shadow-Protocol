
#include "World.h"

void World::AddObstacle(const AABB& obstacle)
{
    obstacles.push_back(obstacle);
}

const std::vector<AABB>& World::GetObstacles() const
{
    return obstacles;
}
