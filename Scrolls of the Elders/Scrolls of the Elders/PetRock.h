#pragma once
#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>


using namespace std;


class PetRock : public Character
{
public:
	
	PetRock(int inputHealth,  sf::RenderWindow& renderWindow, sf::Texture& petRockTex, Character& player);
	bool alive = true;
	sf::RenderWindow& renderWindow;
	Character& player;
	sf::Texture petRockTex;
	sf::IntRect petRockSkin[3];

	sf::Clock clock;
	sf::Vector2f petRockPos;
	float timer;
	int petRockSkinInt = 0;
	void Update(); // get a reference to the player
	void move();
	void attack();
	
};