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
	ReaperBoss(int inputHealth, sf::RenderWindow& renderwindow, sf::Texture &reaperBossTex, Character& player);
	bool alive = true;
	sf::RenderWindow& renderWindow;
	Character& player;
	sf::Texture reaperBossTex;
	sf::IntRect reaperBossSkin[4];

	sf::Clock clock;
	sf::Vector2f reaperBossPos;
	float timer;
	int reaperBossSkinInt = 0;
	void Update(); // get a reference to the player
	void move();
	void attack();
	~ReaperBoss();
};

