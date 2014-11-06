#pragma once

#include "../system.hpp"
#include "../component/position_component.hpp"

class RenderSystem : public System
{
public:
    typedef System super;
    RenderSystem();

    virtual void Render(Entity* entity);
};
