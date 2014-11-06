#include "movement_system.hpp"
#include "../../component/position_component.hpp"
#include "../../component/velocity_component.hpp"

MovementSystem::MovementSystem() :
        super({ PositionComponent::ID, VelocityComponent::ID })
{

}


void MovementSystem::Tick(Entity* entity, float delta)
{
    PositionComponent* position = (PositionComponent*) entity->component(PositionComponent::ID);
    VelocityComponent* velocity = (VelocityComponent*) entity->component(VelocityComponent::ID);

    position->x += velocity->x * delta;
    position->y += velocity->y * delta;
    position->z += velocity->z * delta;
}
