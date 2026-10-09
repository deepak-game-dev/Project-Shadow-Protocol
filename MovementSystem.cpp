#include "MovementSystem.h"
#include "Vector3.h"

void MovementSystem::Update(
    MovementData& movement,
    Vector3 direction,
    float dt)
{
    if (direction.Magnitude() > 0.0f)
    {
        direction = direction.Normalized();

        Vector3 acceleration =
            direction * movement.acceleration;

        movement.velocity =
            movement.velocity + acceleration * dt;
    }
    else
    {
        float deceleration = movement.acceleration;
        float speed = movement.velocity.Magnitude();

        if (speed > 0.0f)
        {
            speed -= deceleration * dt;

            if (speed < 0.0f)
                speed = 0.0f;

            movement.velocity =
                movement.velocity.Normalized() * speed;
        }
    }

    if (movement.velocity.Magnitude() > movement.speed)
    {
        movement.velocity =
            movement.velocity.Normalized() * movement.speed;
    }

    Vector3 movementAmount =
        movement.velocity * dt;

    movement.position =
        movement.position + movementAmount;
}