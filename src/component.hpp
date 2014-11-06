#pragma once

class Component {
public:
    Component(unsigned int id);

    unsigned int id() const;

private:
    unsigned int id_;
};