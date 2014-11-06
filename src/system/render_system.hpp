#pragma once

#include "../system.hpp"

class RenderSystem : public System
{
public:
    typedef System super;
    RenderSystem();

    virtual void Render(Entity* entity);
};
