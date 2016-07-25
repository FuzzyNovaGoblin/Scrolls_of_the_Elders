#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "PetRock.h"

#define PI 3.14159265


int main() {
	// load some resources like textures which will be used for the duration of the game
	sf::Texture petRockTex;
	petRockTex.loadFromFile("resources/character/petRock.png");


	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
	sf::View view;
//	window.setFramerateLimit(10);
	std::vector<PetRock> petRockList;

	for (int i = 0; i < 10; i++) { // make 10 enemies 
		PetRock newPetRock(window, petRockTex);
		petRockList.push_back(newPetRock);
	}

	PetRock mini(window, petRockTex);
	Player player(9,9,9,9,9,9,9,9,9,window);
	sf::Sprite backGround;
	sf::Texture backGroundTex;
	backGroundTex.loadFromFile("resources/character/back.png");
	backGround.setTexture(backGroundTex);
	view.setCenter(sf::Vector2f(player.playerSprite.getPosition().x, player.playerSprite.getPosition().y));
	view.setSize(1780, 980);

	while (window.isOpen()) {



		// get all the input first every frame
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		} // input loop ended


		window.setView(view);

		view.setCenter(sf::Vector2f(player.playerSprite.getPosition().x, player.playerSprite.getPosition().y));
	


	
		window.clear();
		window.draw(backGround);
		for (int i = 0; i < petRockList.size(); i++) {
			petRockList.at(i).updatePetRock(player);
		}
		player.update();
		window.display();
	}
}



