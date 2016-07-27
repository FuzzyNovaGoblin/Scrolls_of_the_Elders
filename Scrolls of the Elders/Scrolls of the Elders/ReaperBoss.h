#pragma once
#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

using namespace std;

class ReaperBoss : public Character
{
public:
	ReaperBoss(int inputHealth, sf::RenderWindow& renderwindow, Character& player);
	sf::RenderWindow& renderWindow;
	Character& player;
	sf::Texture reaperBossIdleTex;
	sf::Texture reaperBossSlashTex;
	sf::Texture reaperBossSummonTex;
	sf::Texture reaperBossTeleportTex;
	sf::IntRect reaperBossSkin[5];

	sf::Clock clock;
	sf::Clock attackTime;
	sf::Vector2f reaperBossPos;
	float timer;
	int reaperBossSkinInt = 0;
	void move();
	void attack();
	//void DoShortAttack();
	void Update();
};

