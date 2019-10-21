
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "player.h"
#include "entity.h"

int main(int, char const**)
{
    // Variables
    float playerMovementSpeed = 2;
    int counterWalking = 0;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "I want to learn SFML! W00tsaurs");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture textureLion;
    if (!textureLion.loadFromFile(resourcePath() + "lion.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteLion(textureLion);
    spriteLion.setPosition(500, 500);
    
    // Load a sprite to display
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile(resourcePath() + "spriteWalk.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x/2, window.getSize().y/2);
    spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Zooboomafu!1obe", font, 25);
    text.setColor(sf::Color::White);
    text.setCharacterSize(50);
    text.setPosition(300, 300);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    //music.play();
    
    class player Player1;
    Player1.sprite.setTexture(texturePlayer);
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        

        
        
        
        // Update Player
        Player1.update();
        Player1.updateMovement();
        
        // Draw Player
        window.draw(Player1.sprite);
        //window.draw(Player1.rect);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
