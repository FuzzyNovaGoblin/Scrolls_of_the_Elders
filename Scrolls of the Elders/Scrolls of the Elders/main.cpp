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

	Player myPlayer;

	//Do not include in actual code
	sf::Texture playerTex;



	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");


	while (window.isOpen()) {
		sf::Event event;
	
	//	myPlayer.update(playerSprite);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		
		//Do not include in actual code
	//	window.draw(playerSprite);
		//Do not include in actual code
		
		window.display();
	}
}



