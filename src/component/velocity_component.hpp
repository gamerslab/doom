#pragma once

#include "../component.hpp"

class VelocityComponent : public Component {
public:
    typedef Component super;
    static const unsigned int ID;


    VelocityComponent();

    float x;
    float y;
    float z;
};