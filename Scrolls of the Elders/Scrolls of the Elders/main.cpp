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

	sf::RenderWindow window(sf::VideoMode(400, 200), "Scrolls of the Elders ");

	while (window.isOpen()) {
		sf::Event event;
		sf::Texture texture;
		texture.loadFromFile("petRock.png");
		sf::Sprite petRock(texture);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		
		window.display();
	}
}



