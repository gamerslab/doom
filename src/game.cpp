#include <GL/glew.h>
#include <sstream>
#include <iostream>
#include <SFML/System.hpp>
#include "game.hpp"
#include "debug.hpp"
#include "audio/music.hpp"
#include "audio/sound.hpp"
#include "screen/level_screen.hpp"

const unsigned char Game::ACTION_KEY = 'z';
const int Game::SCALE = 2;
const int Game::MIN_WINDOW_WIDTH = 800;
const int Game::MIN_WINDOW_HEIGHT = 600;
const int Game::MIN_WIDTH = MIN_WINDOW_WIDTH / SCALE;
const int Game::MIN_HEIGHT = MIN_WINDOW_HEIGHT / SCALE;

int Game::WINDOW_WIDTH = 1024;
int Game::WINDOW_HEIGHT = 768;
int Game::WIDTH = Game::WINDOW_WIDTH / Game::SCALE;
int Game::HEIGHT = Game::WINDOW_HEIGHT / Game::SCALE;
bool Game::DIRTY = true;
GLuint Game::FRAMEBUFFER_AUX = 0;
GLuint Game::RENDERBUFFER_AUX = 0;
Game Game::INSTANCE;
sf::Vector2u Game::TEXTURE_SIZE;

GLuint Game::FramebufferAux() {
    if(FRAMEBUFFER_AUX && DIRTY) {
        glDeleteRenderbuffers(1, &RENDERBUFFER_AUX);
        glDeleteFramebuffers(1, &FRAMEBUFFER_AUX);

        FRAMEBUFFER_AUX = 0;
        RENDERBUFFER_AUX = 0;
        DIRTY = false;
    }

    if(!FRAMEBUFFER_AUX) {
		GLuint fbo, render_buf;
        glGenFramebuffers(1, &fbo);
        glGenRenderbuffers(1, &render_buf);
        glBindRenderbuffer(GL_RENDERBUFFER, render_buf);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, WINDOW_WIDTH, WINDOW_HEIGHT);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, fbo);
        glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, render_buf);

        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        RENDERBUFFER_AUX = render_buf;
        FRAMEBUFFER_AUX = fbo;
    }

    return FRAMEBUFFER_AUX;
}

void Game::Error(const char* error, const std::string& wat) {
    std::stringstream ss;
    ss << error << ' ' << wat;

    std::cerr << ss.str() << std::endl;
    std::exit(1);
}

Game::Game()
{
    screen = 0;
    old_screen = 0;
    current_time = 0;
    dt = 0.016;
    accumulator = 0.0;
    bound = false;

    for(int i = 0; i < 256; ++i) {
        keys[i] = false;
    }
}

Game::~Game()
{
    if(screen)
        delete screen;

    if(old_screen)
        delete old_screen;
}

void Game::Init()
{
    //Graphics initialization
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glViewport(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Perspective mode
    //glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, 1);

    gluPerspective(100, Game::WINDOW_WIDTH / Game::WINDOW_HEIGHT, 0.01, 1000);

    glMatrixMode(GL_MODELVIEW);

    texture = new sf::Texture();
    if(!texture->loadFromFile("res/atlas.png"))
        Game::Error("Error loading atlas texture: ", "res/atlas.png");

    TEXTURE_SIZE = texture->getSize();

    // Set seed
    std::srand((unsigned int)std::time(0));

    LoadLevel("test");

    // Restart the clock
    clock.restart();
}

bool Game::Tick()
{
    float newTime = clock.getElapsedTime().asSeconds();
    float frame_time = newTime - current_time;

    current_time = newTime;
    accumulator += frame_time;

    bool updated = accumulator >= dt;

    while(accumulator >= dt) {
        Update(dt);
        accumulator -= dt;
    }

    return updated;
}

void Game::Finalize()
{
}

void Game::ReadKeyboard(unsigned char key, bool press)
{
	keys[key] = press;

    if(key == 'a' && press)
        Debug::enabled = !Debug::enabled;
}

void Game::Update(double delta)
{
    Music::Update(delta);
    Sound::Update(delta);

    screen->Tick(delta);
}

void Game::Render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(Game::SCALE, Game::SCALE, Game::SCALE);

    screen->Render();
}

void Game::Reshape(int width, int height) {
    // TODO: Port to SFML
    /*if(width < MIN_WINDOW_WIDTH) {
        glutReshapeWindow(MIN_WINDOW_WIDTH, height);
        return;
    }

    if(height < MIN_WINDOW_HEIGHT) {
        glutReshapeWindow(width, MIN_WINDOW_HEIGHT);
        return;
    }

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);

    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    WIDTH = WINDOW_WIDTH / SCALE;
    HEIGHT = WINDOW_HEIGHT / SCALE;
    RECTANGLE = RectangleShape(0, 0, WIDTH, HEIGHT);
    DIRTY = true;*/
}

void Game::ChangeScreen(GameScreen* screen) {
    if(old_screen)
        delete old_screen;

    old_screen = this->screen;
    this->screen = screen;
    this->screen->Init();
}

void Game::LoadTitleScreen() {
    //ChangeScreen(new TitleScreen());
}

void Game::LoadLevel(const char* name) {
    ChangeScreen(new LevelScreen(name));
}

void Game::Over(const std::string& from_level_name) {
    //ChangeScreen(new OverScreen(from_level_name));
}

void Game::Win() {
    //ChangeScreen(new WinScreen());
}

void Game::Exit() {
    std::exit(0);
}

bool Game::ConsumeKey(const char key) {
    bool value = keys[key];
    keys[key] = false;
    return value;
}

bool Game::IsKeyPressed(sf::Keyboard::Key key) const {
    return keys[key];
}

void Game::Bind() {
    // Bind atlas texture
    sf::Texture::bind(texture, sf::Texture::Pixels);
}
