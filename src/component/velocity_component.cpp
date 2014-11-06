#include "velocity_component.hpp"

const unsigned int VelocityComponent::ID = 2;

VelocityComponent::VelocityComponent() :
        super(ID),
        x(0),
        y(0),
        z(0)
{

}
