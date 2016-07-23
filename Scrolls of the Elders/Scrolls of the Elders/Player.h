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
	sf::RenderWindow& renderWindow;
	sf::Sprite playerSprite;
	sf::Texture playerTex;
	sf::IntRect playerSkin[4];
	sf::IntRect petRockSkin[3];
	int playerSkinInt = 0;
	sf::Clock clock;
	Player();


	Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow);

	~Player();

	MeleeWeapon rightHandWeapon;

	sf::Vector2f playerPos;
	
	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character target); //Attack Function (Sword)
	void equipMelee(MeleeWeapon meleeWeapon); //Equips the weapon
	void update();
};

