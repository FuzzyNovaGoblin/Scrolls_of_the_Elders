#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>


class PetRock :
	public Enemy
{
public:
	
	sf::RenderWindow& renderWindow;
	sf::Sprite petRockSprite;
	sf::Texture petRockTex;
	sf::IntRect petRockSkin[3];

	sf::Clock clock;
	sf::Vector2f petRockPos;
	float timer;
	int petRockSkinInt = 0;
	void updatePetRock(Player &player); // get a reference to the player
	void move(Player &player);
	void attack(Player &player);
	PetRock(sf::RenderWindow& renderWindow, sf::Texture& petRockTex);
	~PetRock();
};