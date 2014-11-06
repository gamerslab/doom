#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include "level.hpp"
#include "system/logic/movement_system.hpp"
#include "component/velocity_component.hpp"
#include "component/sprite_component.hpp"

Level::Level()
{
    Entity* player = new Entity();
    player->AddComponent(&player_position_);
    player->AddComponent(new VelocityComponent());
    entities_.push_back(player);

    Entity* enemy = new Entity();
    PositionComponent* position = new PositionComponent();
    position->z = -2;
    enemy->AddComponent(position);
    enemy->AddComponent(new SpriteComponent(0, 0));
    entities_.push_back(enemy);

    logic_systems_.push_back(new MovementSystem());
    render_system_ = new RenderSystem();
}

void Level::Tick(float delta)
{
    for(LogicSystem* system : logic_systems_)
    {
        for(Entity* entity : entities_)
        {
            if(system->IsCompatible(entity))
            {
                system->Tick(entity, delta);
            }
        }
    }
}

void Level::Render()
{
    glTranslatef(-player_position_.x, -player_position_.y, -player_position_.z);

    glBegin(GL_QUADS);

    for(Entity* entity : entities_)
    {
        if(render_system_->IsCompatible(entity))
        {
            render_system_->Render(entity);
        }
    }

    glEnd();
}
