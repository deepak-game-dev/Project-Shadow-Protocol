
#include "InteractionSystem.h"

bool InteractionSystem::TryInteract(
    MissionObject& object,
    const Vector3& playerPosition,
    float interactionRange) const
{
    if (object.collected)
        return false;

    Vector3 difference = object.position - playerPosition;


    difference.y = 0.0f;

    if (difference.Magnitude() <= interactionRange)
    {
        object.collected = true;
        return true;
    }

    return false;
}
