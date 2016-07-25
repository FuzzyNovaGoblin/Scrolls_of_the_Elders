#pragma once
#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Item.h"

class MeleeWeapon : Item
{
public:
	MeleeWeapon();
	MeleeWeapon(string inputName, string inputDescription, int inputWeight, int inputValue, int inputDamage, string inputFilename);
	~MeleeWeapon();

	//Weapon Stats

	int damage; //Damage

	//Weapon Looks

	sf::Texture MeleeWeaponTexture;
	sf::Sprite MeleeWeaponSprite;
};

