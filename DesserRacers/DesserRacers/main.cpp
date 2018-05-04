
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
#include "Car.hpp"
#include "Obstacle.hpp"
#include <iostream>
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define SCREEN_TITLE "Sierra Racers"
#define OBSTACLE_SPAWN_FREQUENCY 0.3f

using namespace std;
int main(int, char const**)
{
    int counter = 0;
    //*********************************************************************************************************
    //Description: Creates window with defined parameters from #include DEFINED.HPP
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),SCREEN_TITLE);
    //*********************************************************************************************************
    //INTRO RESOURCE RECOVERY
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "Surface.png"))
        return EXIT_FAILURE;
    
    sf::Sprite sprite(texture);
    //*********************************************************************************************************
    //MAIN MENU RESOURCE RECOVERY
    sf::Texture sierra;
    if(!sierra.loadFromFile(resourcePath() + "desertMenu3.png"))
        return EXIT_FAILURE;
    
    sf::Sprite sierraMenu(sierra);
    
    MainMenu menu(window.getSize().x, window.getSize().y);
   
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "baby blocks.ttf"))
        return EXIT_FAILURE;
    sf::Text text("PRESS THE", font, 40);
    sf::Text spaceText("SPACE", font, 50);
    text.setPosition(10, 780);
    text.setFillColor(sf::Color::White);
    spaceText.setPosition(400, 780);
    spaceText.setFillColor(sf::Color::Black);
    
    //*********************************************************************************************************
    //GAME RESOURCE RECOVERY
    //       ____Car____
    sf::Texture carSprite;
    if(!carSprite.loadFromFile(resourcePath() + "redCar.png")){
        return -1;
    }
    sf::Sprite redCarSpriteSheet(carSprite);
    Car redCar1;
    redCar1.sprite.setTexture(carSprite);
    //       ____Game Background____
    sf::Texture gameBackground;
    if(!gameBackground.loadFromFile(resourcePath() + "gameBackground2.png"))
        return -1;
    sf:: Sprite gameBackgroundSierra(gameBackground);
    //       ____Obstacles____
    vector<Obstacle>::const_iterator iter;
    vector<Obstacle> obstacleArray1;
    vector<Obstacle> obstacleArray2;
    
    sf::Clock currentTime;
    //*********************************************************************************************************
    //Description:
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "videoplayback.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
   
    //FIRST GAME LOOP
    while(window.isOpen()){
        sf::Event event;
        Obstacle newObs;
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
                                        //Enters Game State
                                        while (window.isOpen())
                                        {
                                            while (window.pollEvent(event))
                                            {
                                                switch (event.key.code)
                                                {
                                                    case sf::Keyboard::Up:
                                                        cout << "create boolean that is true to run make obstacles fall" << endl;
                                                        break;
                                                    case sf::Keyboard::Right:
                                                        cout << "moving right" << endl;
                                                        break;
                                                    case sf::Keyboard::Left:
                                                        cout << "move left" << endl;
                                                        break;
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
                                            redCar1.updating();
                                            window.draw(gameBackgroundSierra);
                                            Obstacle obstacle;
                                            if(currentTime.getElapsedTime().asSeconds() > OBSTACLE_SPAWN_FREQUENCY){
                                                obstacleArray2.push_back(newObs);
                                                obstacleArray1.push_back(obstacle);
                                                currentTime.restart();
                                            }
                                            counter = 0;
                                            for(iter = obstacleArray1.begin(); iter != obstacleArray1.end(); iter++){
                                                if(counter % 2 == 0){
                                                    obstacleArray1[counter].updating();
                                                    window.draw(obstacleArray1[counter].rectangle);
                                                }
                                                else if(counter % 2 == 1){
                                                    obstacleArray2[counter].updating();
                                                    window.draw(obstacleArray2[counter].rectangle);
                                                }
                                                counter++;
                                                
                                            }
                                            
                                            redCar1.movement();
                                            window.draw(redCar1.sprite);
                                            window.display();
                                    }
                                    //ends Game State
                                    case 1:
                                        cout << "Options" << endl;
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
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                                window.clear();
                            }
                        }
                       
                       
                        
                        window.clear();
                        window.draw(sierraMenu);
                        menu.draw(window);
                        window.display();

                    }
                    break;
                    //end of Main Menu
                
                    
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
