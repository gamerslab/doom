#pragma once

#include "../logic_system.hpp"

class MovementSystem : public LogicSystem
{
public:
    typedef LogicSystem super;
    MovementSystem();

    void Tick(Entity* entity, float delta);
};
