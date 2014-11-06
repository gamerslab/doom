#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include "level.hpp"
#include "system/logic/movement_system.hpp"

Level::Level()
{
    Entity* player = new Entity();
    player->AddComponent(&player_position_);
    entities_.push_back(player);

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

    for(Entity* entity : entities_)
        render_system_->Render(entity);
}
