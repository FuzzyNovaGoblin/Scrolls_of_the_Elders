#pragma once
#include "Character.h"
class Player: Character
{
public:
	Player();
	~Player();

	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
};

