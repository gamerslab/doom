#include "system.hpp"

System::System(const std::vector<unsigned int>& required_components) :
        lock_(0)
{
    for(unsigned int component : required_components)
    {
        lock_ = lock_ | (1 >> component);
    }
}

bool System::IsCompatible(Entity *entity) const
{
    return (entity->key() & lock_) == lock_;
}
