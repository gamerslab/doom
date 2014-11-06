#pragma once

#include "../system.hpp"

class LogicSystem : public System {
public:
    typedef System super;
    LogicSystem(const std::vector<unsigned int>& required_components);

    virtual void Tick(Entity* entity, float delta) = 0;
};
