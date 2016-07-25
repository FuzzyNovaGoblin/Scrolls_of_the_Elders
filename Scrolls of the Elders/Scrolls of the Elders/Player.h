#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "Input.h"

#define PI 3.14159265

class Player: Character
{
public:
	sf::RenderWindow& renderWindow;
	sf::Sprite playerSprite;
	sf::Texture playerIdleTex;
	sf::Texture playerForwardTex;
	sf::Texture playerRightTex;
	sf::Texture playerLeftTex;
	sf::Texture playerBackTex;
	sf::IntRect playerSkin[4];
	sf::IntRect petRockSkin[3];
	float animationSpeed;
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

