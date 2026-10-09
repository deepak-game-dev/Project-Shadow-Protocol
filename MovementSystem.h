#pragma once

#include "MovementData.h"
#include "Vector3.h"

class MovementSystem
{
public:
    void Update(MovementData& movement, Vector3 direction, float dt);
};