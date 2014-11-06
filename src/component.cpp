#include "component.hpp"

Component::Component(unsigned int id) :
        id_(id)
{

}


unsigned int Component::id() const {
    return id_;
}
