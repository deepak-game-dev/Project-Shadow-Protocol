
#pragma once

#include "Vector3.h"

struct MissionObject
{
    Vector3 position;
    bool collected = false;
};

class InteractionSystem
{
public:
    bool TryInteract(
        MissionObject& object,
        const Vector3& playerPosition,
        float interactionRange) const;
};

