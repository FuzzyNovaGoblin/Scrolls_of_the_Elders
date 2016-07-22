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

	playerTex.loadFromFile("resources/character/char.gif");

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	//Do include in actual code

	sf::RenderWindow window(sf::VideoMode(400, 200), "Scrolls of the Elders ");

	sf::Texture texture;
	texture.loadFromFile("resources/character/petRock.png");

	while (window.isOpen()) {
		sf::Event event;
	
		sf::Sprite petRock(texture);

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



