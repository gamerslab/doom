#include <SFML/Window.hpp>
#include "game.hpp"

int main()
{
    sf::Event event;
    sf::Window window(sf::VideoMode(1024, 768), "Doom");
    window.setFramerateLimit(60);

    Game::INSTANCE.Init();

    while(window.isOpen())
    {
        // Process events
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    Game::INSTANCE.ReadKeyboard(event.key.code, true);
                    break;

                case sf::Event::KeyReleased:
                    Game::INSTANCE.ReadKeyboard(event.key.code, false);
                    break;

                default:
                    break;
            }
        }

        // Tick and render!
        if(Game::INSTANCE.Tick())
        {
            Game::INSTANCE.Render();
        }

        // Swap buffers
        window.display();
    }

    return 0;
}
