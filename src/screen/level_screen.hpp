#pragma once

#include "../game_screen.hpp"
#include "../level.hpp"

class LevelScreen : public GameScreen
{
public:
    typedef GameScreen super;
    LevelScreen(const char* name);
    ~LevelScreen();

    void Tick(double delta);
    void Render();

private:
    Level* level;
};
