#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "MainMenu.hpp"
#include "Car.hpp"
#include "Obstacle.hpp"
#include "Entity.hpp"
#include <fstream>
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 1000
#define SCREEN_TITLE "SierraRacers"
#define OBSTACLE_SPAWN_FREQUENCY 0.9f
using namespace std;

void gameState(sf::RenderWindow& window){
	int highScore,counter=0,distance = 0;
	bool pause = false;
	/*
	sf::Font Nfont;
    Nfont.loadFromFile("Capture it.ttf");
	sf::Text numberForHighScore("0" ,Nfont, 30);
    numberForHighScore.setPosition(570, 394);
    numberForHighScore.setFillColor(sf::Color::White);
    //      ____CurrentScore____
    sf::Text numberForCurrentScore("0", Nfont, 30);
    numberForCurrentScore.setPosition(570, 318);
    numberForCurrentScore.setFillColor(sf::Color::White);
    //      ____DistanceTracker_____
    sf::Text distanceText("km", Nfont, 60);
    distanceText.setFillColor(sf::Color::Black);  //      ____BestScore____
	*/
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    sf::Text text("PRESS THE", font, 20);
    sf::Text spaceText("SPACE TO START AGAIN", font, 30);

	sf::Text player1("PLAYER TWO WINS",font, 30);
	player1.setPosition(50,80);
	player1.setFillColor(sf::Color::White);	

	sf::Text player2("PLAYER ONE WINS",font, 30);
	player2.setPosition(50,80);
	player2.setFillColor(sf::Color::White);

    text.setPosition(10, 740);
    text.setFillColor(sf::Color::White);
    spaceText.setPosition(60, 780);
    spaceText.setFillColor(sf::Color::Black);

	
//////////////////////////////////////////////////////////////////////////////////////////////
	sf::Texture carSprite;
	carSprite.loadFromFile("redCar.png");
	sf::Sprite redCarSpriteSheet(carSprite);
	Car redCar1('A');
	redCar1.sprite.setTexture(carSprite);
///////////
	sf::Texture carSprite2;
	carSprite2.loadFromFile("image.png");
	sf::Sprite redCarSpriteSheet2(carSprite2);
	Car redCar2('B');
	redCar2.sprite.setTexture(carSprite2);


	sf::Texture carSprite3;
	carSprite3.loadFromFile("redCar.png");
	sf::Sprite redCarSpriteSheet3(carSprite3);
	Car redCar3('B');
	redCar3.sprite.setTexture(carSprite3);


///////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture gameBackground;
    if(!gameBackground.loadFromFile("gameBackground2.png"))
        cout << "err";
    sf::Sprite gameBackgroundSierra(gameBackground);
    //       ____Obstacles____

    sf::Texture textureCow;
    if(!textureCow.loadFromFile("piggy2.png"))
        cout << "err\n";

    vector<Obstacle>::const_iterator iter;
    vector<Obstacle> obstacleArray1;
    vector<Obstacle> obstacleArray2;
    Obstacle obstacle;
    
    obstacle.sprite.setTexture(textureCow);
    
    sf::Clock currentTime;
    sf::Clock distanceClock;
	
	while(window.isOpen()){
		sf::Event event;
		//handle the elements
		while(window.pollEvent(event)){
			switch(event.key.code){
				case sf::Keyboard::Escape:
					window.close();
					break;
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		redCar2.updating();
		redCar1.updating();
		window.draw(gameBackgroundSierra);
		//actual loop
		if(currentTime.getElapsedTime().asSeconds() > OBSTACLE_SPAWN_FREQUENCY && pause == false){
			obstacleArray1.push_back(obstacle);
			currentTime.restart();
		}
		//drawing the obstacles
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
		//collision stuff
		counter = 0;
		for(iter = obstacleArray1.begin(); iter != obstacleArray1.end(); iter++){
			if(obstacleArray1[counter].rectangle.getGlobalBounds().intersects(redCar1.rectangle.getGlobalBounds())){
				pause = true;
				window.draw(text);
				window.draw(spaceText);
				window.draw(player1);
				switch(event.key.code){
					case sf::Keyboard::Space:
						pause = false;
						window.clear();
						gameState(window);
				}
						//window.clear();						//gameState(window);
			}
			counter++;
		}
		//car 2 collision
		
		counter = 0;
		for(iter = obstacleArray1.begin(); iter != obstacleArray1.end(); iter++){
			if(obstacleArray1[counter].rectangle.getGlobalBounds().intersects(redCar2.rectangle.getGlobalBounds())){
				pause = true;
				window.draw(text);
				window.draw(spaceText);
				window.draw(player2);
				switch(event.key.code){
					case sf::Keyboard::Space:
						//pause = false;
						window.clear();
						gameState(window);
				}
			}
			counter++;
		}
		//car moving
		if(pause==false)
			redCar1.movement();
		if(pause == false)
			redCar2.movement();
		window.draw(redCar1.sprite);
		window.draw(redCar2.sprite);
		window.display();
	}
    
}

void otherMenu(sf::RenderWindow& window) {
	//sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);
    sf::Texture sierra;
    sierra.loadFromFile("desertMenu3.png");
    sf::Sprite sierraMenu(sierra);
	MainMenu menu(window.getSize().x, window.getSize().y);
	while(window.isOpen()){
		sf::Event event;
		//handle the elements
		while(window.pollEvent(event)){
			switch(event.key.code){
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:	 				
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getSelectedItemIndex()){
						case 0:
							gameState(window);
							break;
						case 2:
							cout << "hi" << endl;
							window.close();
							break;				
					}
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sierraMenu);
		menu.draw(window);
		window.display();
	}
}



int main() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);

	sf::Texture texture;
	texture.loadFromFile("sur.png");
	sf::Sprite startWindow(texture);

    sf::Music music;
    music.openFromFile("videoplayback.ogg");
    music.play();
    sf::SoundBuffer soundBuffer;

    sf::Font font;
    if (!font.loadFromFile("baby blocks.ttf"))
        return EXIT_FAILURE;
    sf::Text text("PRESS THE", font, 40);
    sf::Text spaceText("SPACE", font, 50);
    text.setPosition(10, 780);
    text.setFillColor(sf::Color::White);
    spaceText.setPosition(400, 780);
    spaceText.setFillColor(sf::Color::Black);

	while(window.isOpen()){
		sf::Event event;
		//handle the elements
		while(window.pollEvent(event)){
			switch(event.key.code){
				case sf::Keyboard::Space:
					otherMenu(window);
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(startWindow);
		window.draw(text);
		window.draw(spaceText);
		window.display();
	}	
	return 0;
}




