#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"

class Player: Character
{
public:
	Player();
	~Player();

	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
};

