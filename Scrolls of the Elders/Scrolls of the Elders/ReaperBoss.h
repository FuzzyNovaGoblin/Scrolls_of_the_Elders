#pragma once
#include "Character.h"
#include "Spheres.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

#include "Map.h"

using namespace std;

class ReaperBoss : public Character
{
public:
	ReaperBoss(int inputHealth, sf::RenderWindow& renderwindow, Character& player, float &DeltaTime, Map &map);
	sf::RenderWindow& renderWindow;
	Character& player;
	sf::Texture reaperBossIdleTex;
	sf::Texture reaperBossSlashTex;
	sf::Texture reaperBossSummonTex;
	sf::Texture reaperBossTeleportTex;
	sf::Texture reaperBossCrystalSpikeTex;
	sf::Texture reaperBossBeamTex;
	sf::Sprite LongAttackSprite;
	sf::IntRect reaperBossSkin[5];
	sf::IntRect reaperBossCrystalSpike[5];
	sf::IntRect reaperBossBeamRect[3];


	std::vector<std::unique_ptr<Spheres>> orbs;

	bool attacking;
	sf::Clock clock;
	sf::Clock attackTime;
	sf::Clock LongAttackAnimation;
	sf::Clock LongAttackTime;
	float timer;
	int reaperBossSkinInt = 0;
	int reaperBossLongAttackInt = 0;
	void crystalSpike();
	void reaperBossBeam();
	void move();
	void attack();
	void DoShortAttack();
	void DoLongAttack();
	void OrbAttack();
	float attackStage = 1;
	int RangedAttacks;
	bool spikeAttack = false;
	bool reaperBossBeamUsed = false;
	bool orbsAttacking = false;
	void Update();
	int reaperBossBeamInt = 0;
};

