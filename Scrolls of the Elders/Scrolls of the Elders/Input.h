#pragma once
#include <SFML/Graphics.hpp>
class Input
{
public:
	Input();
	~Input();
	void Listen(sf::Event& event) {
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				//movingUp = true;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				//movingDown = true;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				//movingLeft = true;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				//movingRight = true;
			}
		}

		//Expand for KeyReleased code.
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				//movingUp = false;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				//movingDown = false;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				//movingLeft = false;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				//movingRight = false;
			}
		}

	}
};
