#include "position_component.hpp"

const unsigned int PositionComponent::ID = 1;

PositionComponent::PositionComponent() :
        super(ID),
        x(0),
        y(0),
        z(0)
{

}
