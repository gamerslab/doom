#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <iostream>
#include "render_system.hpp"
#include "../component/position_component.hpp"
#include "../component/sprite_component.hpp"

RenderSystem::RenderSystem() :
        super({ PositionComponent::ID, SpriteComponent::ID })
{

}

void RenderSystem::Render(Entity* entity)
{
    PositionComponent* position = (PositionComponent*) entity->component(PositionComponent::ID);
    SpriteComponent* sprite = (SpriteComponent*) entity->component(SpriteComponent::ID);

    glTexCoord2f(sprite->x, sprite->y + 64);
    glVertex3f(position->x - 29, position->y, -100);

    glTexCoord2f(sprite->x + 58, sprite->y + 64);
    glVertex3f(position->x + 29, position->y, -100);

    glTexCoord2f(sprite->x + 58, sprite->y);
    glVertex3f(position->x + 29, position->y + 64, -100);

    glTexCoord2f(sprite->x, sprite->y);
    glVertex3f(position->x - 29, position->y + 64, -100);
}
