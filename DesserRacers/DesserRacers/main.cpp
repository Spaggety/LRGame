
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "MainMenu.hpp"
#include <iostream>
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define SCREEN_TITLE "Dessert Racers"

using namespace std;
int main(int, char const**)
{
    //*********************************************************************************************************
    //Description: Creates window with defined parameters from #include DEFINED.HPP
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),SCREEN_TITLE);
    //*********************************************************************************************************
    //Description:
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "Surface.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    //*********************************************************************************************************
    //Description:
    sf::Texture sierra;
    if(!sierra.loadFromFile(resourcePath() + "desertMenuUp.png")){
        return EXIT_FAILURE;
    }
    sf::Sprite sierraMenu(sierra);
    
    //*********************************************************************************************************
    //Description:
    MainMenu menu(window.getSize().x, window.getSize().y);
    //*********************************************************************************************************
    //Description:
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "baby blocks.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("PRESS THE", font, 40);
    sf::Text spaceText("SPACE", font, 50);
    text.setPosition(10, 780);
    text.setFillColor(sf::Color::White);
    spaceText.setPosition(400, 780);
    spaceText.setFillColor(sf::Color::Black);
    //*********************************************************************************************************
    //Description:
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "videoplayback.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            
            switch (event.key.code)
            {
                case sf::Keyboard::Space:
                    //Main Menu State
                    while (window.isOpen())
                    {
                        // Process events
                        while (window.pollEvent(event))
                        {
                            
                            switch (event.key.code){
                                case sf::Keyboard::Up:
                                    menu.moveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    menu.moveDown();
                                    break;
                                case sf::Keyboard::Return:
                                    switch (menu.getSelectedItemIndex())
                                {
                                    case 0:
                                        //Game State 
                                        break;
                                    case 1:
                                        cout << "Options not available" << endl;
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                    
                            }
                            // Close window: exi/Users/Wicky/Desktop/ResourcePath.mmt
                            if (event.type == sf::Event::Closed) {
                                window.close();
                            }
                            
                            // Escape pressed: exit
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                                window.clear();
                            }
                        }
                    
                        window.clear();
                        window.draw(sierraMenu);
                        menu.draw(window);
                        window.display();

                    }
                    break;
                
                    
            // Close window: exi/Users/Wicky/Desktop/ResourcePath.mmt
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                window.clear();
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(spaceText);
        window.display();
    
    }
    
}


}










