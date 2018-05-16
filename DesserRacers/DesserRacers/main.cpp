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
#include "GameOverMenu.hpp"
#include "ResourcePath.hpp"
#include "MainMenu.hpp"
#include "Car.hpp"
#include "Obstacle.hpp"
#include <iostream>
#include <fstream>
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define SCREEN_TITLE "Sierra Racers"
#define OBSTACLE_SPAWN_FREQUENCY 0.9f

using namespace std;
int main(int, char const**)
{
    int highScore;
    int counter = 0;
    int distance = 1;
    bool pause = false;
    bool keepGoing =false;
    
    //*********************************************************************************************************
    //Description: Creates window with defined parameters from #include DEFINED.HPP
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),SCREEN_TITLE);
   
    //*********************************************************************************************************
    //      INTRO RESOURCE RECOVERY
    //      ____IntroBackground____
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "Surface.png"))
        return -1;
    sf::Sprite sprite(texture);
    
    //*********************************************************************************************************
    //      MAIN MENU RESOURCE RECOVERY
    //      ____Background____
    sf::Texture sierra;
    if(!sierra.loadFromFile(resourcePath() + "desertMenu3.png"))
        return -1;
    sf::Sprite sierraMenu(sierra);
    //      ____Menu____
    MainMenu menu(window.getSize().x, window.getSize().y);
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "baby blocks.ttf"))
        return -1;
    //      ____FontForDistance____
    sf::Font numberFont;
    if (!numberFont.loadFromFile(resourcePath() + "Capture it.ttf"))
        return -1;

    sf::Text text("PRESS THE", numberFont, 50);
    sf::Text spaceText("SPACE", numberFont, 60);
    sf::Text barKey("BAR", numberFont, 70);
    text.setPosition(40, 780);
    text.setFillColor(sf::Color::White);
    spaceText.setPosition(310, 790);
    spaceText.setFillColor(sf::Color::Black);
    barKey.setPosition(520, 810);
    barKey.setFillColor(sf::Color::Yellow);
    //*********************************************************************************************************
    //       IN GAME RESOURCE RECOVERY
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
    sf::Texture textureCow;
    if(!textureCow.loadFromFile(resourcePath() + "piggy2.png"))
        return -1;
    
    vector<Obstacle>::const_iterator iter;
    vector<Obstacle> obstacleArray1;
    vector<Obstacle> obstacleArray2;
    Obstacle obstacle;
    
    obstacle.sprite.setTexture(textureCow);
    
    sf::Clock currentTime;
    sf::Clock distanceClock;
    //*********************************************************************************************************
    //       GAME OVER RESOURCE RECOVERY
    //       ____GameOverTexture____
    sf::Texture gameOver;
    if(!gameOver.loadFromFile(resourcePath() + "gameOver.png")){
        return -1;
    }
    sf::Sprite gameOverTexture(gameOver);
    gameOverTexture.setPosition(90, 200);
    //      ____BestScore____
    sf::Text numberForHighScore("0" ,numberFont, 30);
    numberForHighScore.setPosition(570, 394);
    numberForHighScore.setFillColor(sf::Color::White);
    //      ____CurrentScore____
    sf::Text numberForCurrentScore("0", numberFont, 30);
    numberForCurrentScore.setPosition(570, 318);
    numberForCurrentScore.setFillColor(sf::Color::White);
    //      ____DistanceTracker_____
    sf::Text distanceText("km", numberFont, 60);
    distanceText.setFillColor(sf::Color::Black);
    //      ____GameOverMenu____
    GameOverMenu gameOverMenu(window.getSize().x, window.getSize().y);
    //      ____GrayBackground____
    sf::Texture grayBackground;
    if(!grayBackground.loadFromFile(resourcePath() + "gray.png"))
        return -1;
    sf::Sprite grayBackgroundTexture(grayBackground);
    grayBackgroundTexture.setPosition(170, 550);
    
    
    //*********************************************************************************************************
    //      MUSIC/SOUND RESOURCE RECOVERY
    //      ___Intro Music___
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "videoplayback.ogg"))
    return EXIT_FAILURE;
    music.play();
    sf::SoundBuffer soundBuffer;
    sf::Sound carStartUp;
//    if(!soundBuffer.loadFromFile(resourcePath() + "carCrash.wav"))
//       return EXIT_FAILURE;
//    carStartUp.setBuffer(soundBuffer);
    
    
    //FIRST GAME LOOP
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
                                        //Enters Game State
                                        distanceClock.restart();
                                        while (window.isOpen())
                                        {
                                            while (window.pollEvent(event))
                                            {
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
                                            redCar1.updating();
                                            window.draw(gameBackgroundSierra);
                                            //Adds objects to vector
                                            if(currentTime.getElapsedTime().asSeconds() > OBSTACLE_SPAWN_FREQUENCY){
                                                if(pause == false){
                                                    obstacleArray1.push_back(obstacle);
                                                    currentTime.restart();
                                                }
                                                
                                            }
                                            //Goes through vector and draws any objects inside the vector
                                            counter = 0;
                                            for(iter = obstacleArray1.begin(); iter != obstacleArray1.end(); iter++){
                                                if(pause == false){
                                                    srand(time(0));
                                                    int derivedRandomNum = (rand() % 8)+1;
                                                    if(derivedRandomNum == 1){
                                                        obstacle.rectangle.setPosition(150,-500);
                                                    }
                                                    else if(derivedRandomNum == 2){
                                                        obstacle.rectangle.setPosition(200, -500);
                                                    }
                                                    else if(derivedRandomNum == 3){
                                                        obstacle.rectangle.setPosition(250, -500);
                                                    }
                                                    else if(derivedRandomNum == 4){
                                                        obstacle.rectangle.setPosition(300,-500);
                                                    }
                                                    else if(derivedRandomNum == 5){
                                                        obstacle.rectangle.setPosition(350,-500);
                                                    }
                                                    else if(derivedRandomNum == 6){
                                                        obstacle.rectangle.setPosition(400, -500);
                                                    }
                                                    else if(derivedRandomNum == 7){
                                                        obstacle.rectangle.setPosition(450, -500);
                                                    }
                                                    else{
                                                        obstacle.rectangle.setPosition(500,-500);
                                                    }
                                                    
                                                    obstacleArray1[counter].updating();
                                                    window.draw(obstacleArray1[counter].sprite);
                                                    counter++;
                                                }
                                                
                                            }
                                            //Collision Tracker
                                            counter = 0;
                                            for(iter = obstacleArray1.begin(); iter != obstacleArray1.end(); iter++){
                                                if(obstacleArray1[counter].rectangle.getGlobalBounds().intersects(redCar1.rectangle.getGlobalBounds())){
                                                    
                                                    pause = true;
                                                    
                                                }
                                                
                                                counter++;
                                            }
                                            //Distance Tracker
                                            if(distanceClock.getElapsedTime().asSeconds() > .5f && pause == false){
                                                if(pause == false){
                                                    distance += 1;
                                                }
                                                
                                                distanceClock.restart();
                                            }
                                            
                                            
                                            if(pause == true){
                                                carStartUp.play();
                                                music.setVolume(30);
                                                window.draw(gameOverTexture);
                                                ifstream readFile;
                                                readFile.open("/Users/Wicky/Desktop/highScore.txt");
                                                if(readFile.is_open()){
                                                    while(!readFile.eof()){
                                                        readFile >> highScore;
                                                    }
                                                }
                                                readFile.close();
                                                
                                                ofstream writeFile("/Users/Wicky/Desktop/highScore.txt");
                                                if(writeFile.is_open()){
                                                    if(distance > highScore){
                                                        highScore = distance;
                                                    }
                                                    writeFile << highScore;
                                                }
                                                writeFile.close();
                                                numberForHighScore.setString(to_string(highScore) + " km");
                                                window.draw(numberForHighScore);
                                                numberForCurrentScore.setString(to_string(distance) + " km");
                                                window.draw(numberForCurrentScore);
//                                                music.pause();
                                                while (window.pollEvent(event)){
                                                    switch (event.key.code){
                                                        case sf::Keyboard::Left:
                                                            gameOverMenu.moveUp();
                                                            break;
                                                        case sf::Keyboard::Right:
                                                            gameOverMenu.moveDown();
                                                            break;
                                                        case sf::Keyboard::Return:
                                                            switch (gameOverMenu.getSelectedItemIndex())
                                                        {
                                                            case 0:
                                                                for(int i = 0; i < obstacleArray1.size(); i++){
                                                                    obstacleArray1.pop_back();
                                                                }
                                                                music.setVolume(100);
                                                                pause = false;
                                                                distance = 0;
                                                                redCar1.rectangle.setPosition(384,800);
                                                                
                                                                break;
                                                                
                                                            case 1:
                                                                window.close();
                                                                break;
                                                                
                                                        }
                                                    }
                                                }
                                                window.draw(grayBackgroundTexture);
                                                gameOverMenu.draw(window);
                                                
                                                
                                            }
                                            if(pause == false){
                                                redCar1.movement();
                                            }
//                                            window.draw(redCar1.rectangle);
                                            window.draw(redCar1.sprite);
                                            distanceText.setString(to_string(distance) + " km");
                                            window.draw(distanceText);
                                            window.display();
                                        }
                                        //ends Game State
                                        break;
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
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                        window.clear();
                    }
            }
            
            window.clear();
            window.draw(sprite);
            window.display();
            
        }
        
    }
    
}

