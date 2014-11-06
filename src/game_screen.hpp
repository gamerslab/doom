#pragma once

class GameScreen {
public:
    GameScreen();

    virtual void Init();
    virtual void Tick(double delta) = 0;
    virtual void Render() = 0;
};
