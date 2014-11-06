#include "movement_system.hpp"
#include "../../component/position_component.hpp"

MovementSystem::MovementSystem() :
        super({ PositionComponent::ID })
{

}


void MovementSystem::Tick(Entity* entity, float delta)
{
    PositionComponent* position = (PositionComponent*) entity->component(PositionComponent::ID);
}
