#include <iostream>
#include "entity.hpp"

Entity::Entity() :
        key_(0)
{
    components_.resize(64, 0);
}

unsigned long Entity::key() const {
    return key_;
}

Component* Entity::component(unsigned int id) const {
    return components_[id];
}

void Entity::AddComponent(Component* component) {
    components_[component->id()] = component;
    key_ = key_ | (1 << component->id());
}
