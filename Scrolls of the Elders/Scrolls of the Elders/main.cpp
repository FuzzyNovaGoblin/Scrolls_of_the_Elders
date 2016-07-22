#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "MeleeWeapon.h"


int main() {

	//Do not include in actual code
	sf::Texture playerTex;

	playerTex.loadFromFile("resources/character/petRock.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	playerSprite.setTextureRect(sf::IntRect(2,2,3,4));
	//Do include in actual code

	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");


	while (window.isOpen()) {
		sf::Event event;
	
	

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		
		//Do not include in actual code
		window.draw(playerSprite);
		//Do not include in actual code
		
		window.display();
	}
}



