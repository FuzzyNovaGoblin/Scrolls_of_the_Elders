#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\Audio.hpp>
#include <memory>

#include "Player.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "PetRock.h"
#include "ReaperBoss.h"
#include "Map.h"

#define PI 3.14159265


void PlayGame(sf::RenderWindow& window) {
	sf::View view;
	sf::Image layout;
	sf::Music theme;
	theme.openFromFile("resources/audio/Child of Light - Boss Battle Theme.wav");
	theme.play();
	
	int mapNum = rand() % 4 + 1;
	
	string mapString("resources/environment/map." + std::to_string(mapNum) + ".png");
	//string mapString("resources/environment/map." + std::to_string(mapNum) + ".png");
	string outputMapString("Loaded Map " + std::to_string(mapNum) + ".");
	cout << outputMapString << endl;

	
	layout.loadFromFile(mapString);

	sf::Texture red;
	sf::Texture green;
	sf::Texture blue;
	sf::Texture black;
	sf::Texture blank;


	red.loadFromFile("resources/environment/darkgrassyrock.jpg");
	green.loadFromFile("resources/environment/playerSpawn.jpg");
	blue.loadFromFile("resources/environment/purplecliffrock.jpg");
	black.loadFromFile("resources/environment/darkgrassyrock.jpg");
	blank.loadFromFile("resources/environment/darkestrock.jpg");

	Map currentMap(window, 150, red, green, blue, black, blank, layout);

	sf::Clock deltaTimeClock;
	float DeltaTime = 0;

	// load some resources like textures which will be used for the duration of the game
	sf::Texture petRockTex;
	petRockTex.loadFromFile("resources/character/petRock.png");
	sf::Clock spawnTime;
	bool pause = false;
	sf::Texture reaperBossIdleTex;
	reaperBossIdleTex.loadFromFile("resources/character/Reaper Boss-Idle.png");


	//window.setFramerateLimit(60);
	//std::vector<Character*> petRockList;
	std::vector<std::unique_ptr<Character>> petRockList;
	MeleeWeapon sword("axe", "gold", 5, 9, 10, "Golden-BattleAxe.png");

	Player player(100, 10, 10, 10, 10, 10, 10, 10, 10, window, petRockList, DeltaTime, currentMap);
	//ReaperBoss reaperBoss(500, window, player);



	player.equipMelee(sword);



	sf::Font asmanFont;
	sf::Text pauseText;
	asmanFont.loadFromFile("resources/font/ASMAN.ttf");
	pauseText.setFont(asmanFont);
	pauseText.setString("Paused");
	pauseText.setCharacterSize(200);
	pauseText.setColor(sf::Color::Red);
	pauseText.setPosition(player.position.x - 350, player.position.y - 20);

	for (int i = 0; i < 10; i++) { // make 10 enemies 
		std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player, DeltaTime, currentMap));
		petRockList.push_back(std::move(newPetRock));
	}
	//ReaperBoss reaperBoss(500, window, player);
	std::unique_ptr<Character> reaperBoss(new ReaperBoss(750, window, player, DeltaTime, currentMap));
	petRockList.push_back(std::move(reaperBoss));



	//sf::Sprite backGround;
	//sf::Texture backGroundTex;
	//backGroundTex.loadFromFile("resources/environment/floorBackground.jpg");
	//backGround.setTexture(backGroundTex);

	//backGround.setScale(5, 5);



	view.setCenter(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y));
	view.setSize(1780, 980);

	while (window.isOpen()) {


		sf::Time timeFromClock = deltaTimeClock.restart();
		DeltaTime = timeFromClock.asSeconds();

		if (spawnTime.getElapsedTime().asSeconds() > 10 && petRockList.size() < 10) {
			for (int i = 0; i < 10; i++) { // make 10 enemies 
				std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player, DeltaTime, currentMap));
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

					   //window.draw(backGround);
			currentMap.Update();

			player.Update();

			for (int i = 0; i < petRockList.size(); i++) {
				petRockList.at(i)->Update();
			}
			window.draw(player.scoreText);
		}
		else {
			window.draw(pauseText);
		}


		window.display();
		if (!player.alive) {
			return;
		}
	}
}







int main() {
	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
	int stage = 0;
	srand(time(NULL));
	while (true) {
		
		PlayGame(window);
		stage++;
		//window.clear();
		cout << "Press any key to play again" << endl;
		system("pause");
	
	
	}


}



