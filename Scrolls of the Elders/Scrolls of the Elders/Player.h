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
#include "Map.h"


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
	sf::Clock damageDisplayClock;
	sf::Text healthText;
	sf::Font healthFont;
	sf::Text damageText;
	sf::Text critText;
	//sf::Vector2f targetPosition;
	string scoreString;
	float currentAttackAngle;
	float startingAngle;
	float swingArc; //Arc of the swing
	float swingTime; //Tine in seconds for how long it should take to swing through the full arc
	float degreesPerSecond;
	float stage;
	bool attackState;
	bool attacked;


	Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow, std::vector<std::unique_ptr<Character>>& petRockList, float& DeltaTime, Map &map);

	MeleeWeapon rightHandWeapon;
	std::vector<std::unique_ptr<Character>>& petRockList;
	void attackSFML(float angle); //Actuator and Animation for Attack (Sword)
	void attack(Character& target, int index); //Attack Function (Sword)
	void equipMelee(MeleeWeapon meleeWeapon); //Equips the weapon
	//void damageDisplay(int currentDamage, sf::Vector2f targetPosition);
	void Update();

	//sf::Clock attackTimer;
};

