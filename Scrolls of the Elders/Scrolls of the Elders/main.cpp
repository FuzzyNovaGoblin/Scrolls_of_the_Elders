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

	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
	sf::View view;
//	window.setFramerateLimit(10);
	PetRock mini(window);
	Player player(9,9,9,9,9,9,9,9,9,window);
	sf::Sprite backGround;
	sf::Texture backGroundTex;
	backGroundTex.loadFromFile("resources/character/back.png");
	backGround.setTexture(backGroundTex);
	view.setCenter(sf::Vector2f(player.playerSprite.getPosition().x, player.playerSprite.getPosition().y));
	view.setSize(1780, 980);

	while (window.isOpen()) {
		sf::Event event;

		window.setView(view);

		view.setCenter(sf::Vector2f(player.playerSprite.getPosition().x, player.playerSprite.getPosition().y));
	
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		window.clear();
		window.draw(backGround);
		mini.updatePetRock(player);
		player.update();
		window.display();
	}
}



