#pragma once

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "game_screen.hpp"

class Game
{
public:
    static const unsigned char ACTION_KEY;
    static const int SCALE;
    static const int MIN_WINDOW_WIDTH;
    static const int MIN_WINDOW_HEIGHT;
    static const int MIN_WIDTH;
    static const int MIN_HEIGHT;
    static int WINDOW_WIDTH;
    static int WINDOW_HEIGHT;
    static int WIDTH;
    static int HEIGHT;
    static bool DIRTY;
    static Game INSTANCE;
    static sf::Vector2u TEXTURE_SIZE;

    static GLuint FramebufferAux();
    static void Error(const char* error, const std::string& wat);

	Game();
	virtual ~Game();

    bool ConsumeKey(const char key);
    bool IsKeyPressed(sf::Keyboard::Key key) const;

	void Init();
    void Bind();
	bool Tick();
	void Finalize();

    void LoadTitleScreen();
    void LoadLevel(const char* name);
    void Over(const std::string& from_level_name);
    void Win();
    void Exit();

	void ReadKeyboard(unsigned char key, bool press);
    void Update(double delta);
	void Render();
    void Reshape(int width, int height);

private:
    static GLuint FRAMEBUFFER_AUX;
    static GLuint RENDERBUFFER_AUX;

    sf::Clock clock;
	bool keys[256];
    GameScreen* screen;
    GameScreen* old_screen;
    sf::Texture* texture;

    // Timing variables
    float current_time;
    float dt;
    float accumulator;
    bool bound;

    void ChangeScreen(GameScreen* screen);
};
