#include "sprite_component.hpp"

const unsigned int SpriteComponent::ID = 3;

SpriteComponent::SpriteComponent(float x, float y) :
        super(ID),
        x(x),
        y(y)
{

}
