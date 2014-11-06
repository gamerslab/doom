#pragma once

#include "entity.hpp"
#include "system/logic_system.hpp"
#include "system/render_system.hpp"
#include "component/position_component.hpp"

class Level
{
public:
    Level();

    void Tick(float delta);
    void Render();

private:
    std::vector<Entity*> entities_;
    std::vector<LogicSystem*> logic_systems_;
    RenderSystem* render_system_;
    PositionComponent player_position_;
};
