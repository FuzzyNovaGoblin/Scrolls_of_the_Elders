#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <memory>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Character.h"
#include "Item.h"
#include "MeleeWeapon.h"
#include "Input.h"


#define PI 3.14159265

using namespace std;

class Player: public Character
{
public:
	//int score;
	sf::Font asmanFont;
	sf::Text scoreText;
	sf::RenderWindow& renderWindow;
	sf::Texture playerIdleTex;
	sf::Texture playerForwardTex;
	sf::Texture playerRightTex;
	sf::Texture playerLeftTex;
	sf::Texture playerBackTex;
	sf::IntRect playerSkin[4];
	sf::IntRect petRockSkin[3];
	float animationSpeed;
	int playerSkinInt = 0;
	bool alive;
	sf::Clock clock;
	sf::Text healthText;
	sf::Font healthFont;
	string scoreString;


	Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow, std::vector<std::unique_ptr<Character>>& petRockList, float& DeltaTime);

	MeleeWeapon rightHandWeapon;
	std::vector<std::unique_ptr<Character>>& petRockList;
	void attackSFML(); //Actuator and Animation for Attack (Sword)
	void attack(Character& target); //Attack Function (Sword)
	void equipMelee(MeleeWeapon meleeWeapon); //Equips the weapon
	void Update();
};

