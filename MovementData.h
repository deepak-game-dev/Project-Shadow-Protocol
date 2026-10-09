#pragma once

#include "Vector3.h"

struct MovementData
{
    Vector3 position;
    Vector3 velocity;

    float speed = 5.0f;
    float acceleration = 10.0f;
};