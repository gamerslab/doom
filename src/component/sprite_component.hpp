#pragma once

#include "../component.hpp"

class SpriteComponent : public Component
{
public:
    typedef Component super;
    static const unsigned int ID;

    SpriteComponent(float x, float y);

    float x;
    float y;
};
