#pragma once

#include "entity.hpp"

class System {
public:
    System(const std::vector<unsigned int>& required_components);

    bool IsCompatible(Entity* entity) const;

private:
    unsigned long lock_;
};
