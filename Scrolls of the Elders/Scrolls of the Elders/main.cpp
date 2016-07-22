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
#include "PetRock.h"


int main() {

	sf::RenderWindow window(sf::VideoMode(1780, 980), "Scrolls of the Elders ");
//	window.setFramerateLimit(10);
	PetRock mini(window);
	Player player(9,9,9,9,9,9,9,9,9);
	float playerX = 0; 
	float playerY = 0;
	while (window.isOpen()) {
		sf::Event event;
	
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		window.clear();
		mini.updatePetRock(); 
		
		window.display();
	}
}



