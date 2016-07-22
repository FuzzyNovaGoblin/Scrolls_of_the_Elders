#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Item.h"
#include "MeleeWeapon.h"

class Player: Character
{
public:
	Player();
	~Player();

	MeleeWeapon rightHandWeapon;

	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
	void equipMelee(MeleeWeapon meleeWeapon); //Equips the melee weapon
};

