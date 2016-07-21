#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>


int main() {

	sf::RenderWindow window(sf::VideoMode(400, 200), "Scrolls of the Elders ");

	while (window.isOpen()) {
		sf::Event event;
		sf::Texture texture;
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

