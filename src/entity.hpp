#pragma once

#include <vector>
#include "component.hpp"

class Entity {
public:
    Entity();

    unsigned long key() const;
    Component* component(unsigned int id) const;

    void AddComponent(Component* component);

private:
    unsigned long key_;
    std::vector<Component*> components_;
};
