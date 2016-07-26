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

#define PI 3.14159265


int main() {
	// load some resources like textures which will be used for the duration of the game
	sf::Texture petRockTex;
	petRockTex.loadFromFile("resources/character/petRock.png");
	sf::Clock spawnTime;

	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
	sf::View view;
//	window.setFramerateLimit(10);
	//std::vector<Character*> petRockList;
	std::vector<std::unique_ptr<Character>> petRockList;
	MeleeWeapon sword ("sword", "steel", 5, 9, 10, "Worn-Steel-Sword.png");

	Player player(50,10,10,10,10,10,10,10,10, window, petRockList);

	player.equipMelee(sword);



	for (int i = 0; i < 10; i++) { // make 10 enemies 
		std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player));
		petRockList.push_back(std::move(newPetRock));
	}

	sf::Sprite backGround;
	sf::Texture backGroundTex;
	backGroundTex.loadFromFile("resources/environment/BrickBackground.jpg");
	backGround.setTexture(backGroundTex);

	backGround.setScale(50, 50);

	view.setCenter(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y));
	view.setSize(1780, 980);

	while (window.isOpen()) {


		if (spawnTime.getElapsedTime().asSeconds() > 10) {
			for (int i = 0; i < 10 + player.score; i++) { // make 10 enemies 
				std::unique_ptr<Character> newPetRock(new PetRock(1, window, petRockTex, player));
				petRockList.push_back(std::move(newPetRock));
			}
			spawnTime.restart();
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
		window.draw(backGround);
		player.Update();
		for (int i = 0; i < petRockList.size(); i++) {
			petRockList.at(i)->Update();
		}
	
		window.display();
	}
}



