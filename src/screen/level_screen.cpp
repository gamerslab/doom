#include "level_screen.hpp"

LevelScreen::LevelScreen(const char* name)
{
    level = new Level();
}


LevelScreen::~LevelScreen()
{

}


void LevelScreen::Tick(double delta)
{
    level->Tick(delta);
}

void LevelScreen::Render()
{
    level->Render();
}
