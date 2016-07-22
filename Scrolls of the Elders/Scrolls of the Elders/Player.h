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

	Player(string inputName, string inputDescription, int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::Texture inputTexture, sf::Sprite inputSprite);

	~Player();

	MeleeWeapon rightHandWeapon;

	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
	void equipMelee(MeleeWeapon meleeWeapon); //Equips the weapon
	void update();
};

