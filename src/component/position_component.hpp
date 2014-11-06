#pragma once

#include "../component.hpp"

class PositionComponent : public Component {
public:
    typedef Component super;
    static const unsigned int ID;

    float x;
    float y;
    float z;

    PositionComponent();
};
