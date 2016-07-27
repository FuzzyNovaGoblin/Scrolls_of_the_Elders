#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>
#include <memory>


#include "Player.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "PetRock.h"
#include "ReaperBoss.h"

#define PI 3.14159265


int main() {

	sf::Clock deltaTimeClock;
	float DeltaTime = 0;

	// load some resources like textures which will be used for the duration of the game
	sf::Texture petRockTex;
	petRockTex.loadFromFile("resources/character/petRock.png");
	sf::Clock spawnTime;
	bool pause = false;
	sf::Texture reaperBossIdleTex;
	reaperBossIdleTex.loadFromFile("resources/character/Reaper Boss-Idle.png");
	
	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
	sf::View view;
//	window.setFramerateLimit(10);
	//std::vector<Character*> petRockList;
	std::vector<std::unique_ptr<Character>> petRockList;
	MeleeWeapon sword ("axe", "gold", 5, 9, 10, "Golden-BattleAxe.png");

	Player player(50,10,10,10,10,10,10,10,10, window, petRockList, DeltaTime);
	ReaperBoss reaperBoss(500, window, player);
	player.equipMelee(sword);



	sf::Font asmanFont;
	sf::Text pauseText;
	asmanFont.loadFromFile("resources/font/ASMAN.ttf");
	pauseText.setFont(asmanFont);
	pauseText.setString("Paused");
	pauseText.setCharacterSize(200);
	pauseText.setColor(sf::Color::Red);
	pauseText.setPosition(player.position.x - 350, player.position.y - 20);

	for (int i = 0; i < 10+player.score; i++) { // make 10 enemies 
		std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player, DeltaTime));
		petRockList.push_back(std::move(newPetRock));
	}

	sf::Sprite backGround;
	sf::Texture backGroundTex;
	backGroundTex.loadFromFile("resources/environment/BrickBackground.jpg");
	backGround.setTexture(backGroundTex);

	backGround.setScale(5, 5);

	view.setCenter(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y));
	view.setSize(1780, 980);

	while (window.isOpen()) {


		sf::Time timeFromClock = deltaTimeClock.restart();
		DeltaTime = timeFromClock.asSeconds();

		if (spawnTime.getElapsedTime().asSeconds() > 10 && petRockList.size() < 500 && player.score<100) {
			for (int i = 0; i < 10 + player.score; i++) { // make 10 enemies 
				std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player, DeltaTime));
				petRockList.push_back(std::move(newPetRock));
			}
			spawnTime.restart();
		}
		else if (spawnTime.getElapsedTime().asSeconds() > 10 && petRockList.size() < 500 && player.score >= 100) {
			for (int i = 0; i < 100; i++) { // make 10 enemies 
				std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player, DeltaTime));
				petRockList.push_back(std::move(newPetRock));
			}
			spawnTime.restart();
		}

		

		if (!pause && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			pause = true;
		}
		if (pause && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			pause = false;
		}
		// get all the input first every frame
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		} // input loop ended


		window.setView(view);

		view.setCenter(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y));
	
		window.clear();


		if (!pause) {  //This is the pause function

			window.draw(backGround);

			player.Update();

			//reaperBoss.Update();

			for (int i = 0; i < petRockList.size(); i++) {
				petRockList.at(i)->Update();
			}
			window.draw(player.scoreText);
		}
		else {
			window.draw(pauseText);
		}


		window.display();
	}
}



