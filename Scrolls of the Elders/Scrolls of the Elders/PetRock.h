#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>
class PetRock :
	public Enemy
{
public:
	sf::Sprite petRockSprite;
	sf::RenderWindow renderWindow;
	float timer;
	int petRockSkinInt = 0;
	void updatePetRock();
	PetRock(sf::RenderWindow& renderWindow);
	~PetRock();
};

