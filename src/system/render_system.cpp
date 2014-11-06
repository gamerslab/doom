#include "render_system.hpp"
#include "../component/position_component.hpp"

RenderSystem::RenderSystem() :
        super({ PositionComponent::ID })
{

}

void RenderSystem::Render(Entity* entity)
{
    PositionComponent* position = (PositionComponent*) entity->component(PositionComponent::ID);


}
