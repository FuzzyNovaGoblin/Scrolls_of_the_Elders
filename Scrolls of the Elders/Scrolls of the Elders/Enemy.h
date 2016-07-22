#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Player.h"

class Enemy:Character
{
public:

	Enemy();
	~Enemy();
	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
};

