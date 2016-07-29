#include "ReaperBoss.h"

float GetDistance(sf::Vector2f a, sf::Vector2f b);

ReaperBoss::ReaperBoss(int inputHealth, sf::RenderWindow& renderWindow, Character& player, float &DeltaTime, Map &map) : Character(DeltaTime, map), renderWindow(renderWindow), player(player)
{
	reaperBossIdleTex.loadFromFile("resources/character/Reaper Boss-Idle.png");
	reaperBossSlashTex.loadFromFile("resources/character/Reaper Boss-Attack.png");
	reaperBossSummonTex.loadFromFile("resources/character/Reaper Boss-Magic.png");
	reaperBossTeleportTex.loadFromFile("resources/character/Reaper Boss-Teleport.png");
	reaperBossCrystalSpikeTex.loadFromFile("resources/character/Reaper Boss-Attack-Spikes.png");
	reaperBossBeamTex.loadFromFile("resources/character/Reaper Boss-Attack-Beam.png");
	reaperBossSkin[0] = sf::IntRect(0, 0, 192, 192);
	reaperBossSkin[1] = sf::IntRect(192, 0, 192, 192);
	reaperBossSkin[2] = sf::IntRect(0, 192, 192, 192);
	reaperBossSkin[3] = sf::IntRect(192, 192, 192, 192);
	reaperBossSkin[4] = sf::IntRect(0, 384, 192, 192);
	reaperBossCrystalSpike[0] = sf::IntRect(0, 0, 128, 128);
	reaperBossCrystalSpike[1] = sf::IntRect(128, 0, 128, 128);
	reaperBossCrystalSpike[2] = sf::IntRect(0, 128, 128, 128);
	reaperBossCrystalSpike[3] = sf::IntRect(128, 128, 128, 128);
	reaperBossCrystalSpike[4] = sf::IntRect(0, 256, 128, 128);
	reaperBossBeamRect[0] = sf::IntRect(0, 0, 128, 128);
	reaperBossBeamRect[1] = sf::IntRect(128, 0, 128, 128);
	reaperBossBeamRect[2] = sf::IntRect(0, 128, 128, 128);

	healthBar.setFillColor(sf::Color::Red);
	healthBar.setSize(sf::Vector2f(192, 16));
	healthBar.setPosition(position + sf::Vector2f(0, 200));
	
	sprite.setOrigin(96, 96);

	maxHealth = inputHealth;

	currentHealth = maxHealth;

	strength = 10;

	hit = false;

	for (int i = 0; i < map.tiles.size(); i++) {
		if (map.tiles.at(i).bossSpawner) {
			spawnPos[0] = map.tiles.at(i).xPos;
			spawnPos[1] = map.tiles.at(i).yPos;

		}
	}

	/*float tempX = start[0];
	float tempY = start[1];*/

	/*position.x = tempX;
	position.y = tempY;*/

	sprite.setPosition(spawnPos[0], spawnPos[1]);

	sprite.setTexture(reaperBossIdleTex);
	
	timer = clock.getElapsedTime().asSeconds();

}

void ReaperBoss::crystalSpike() {
	if (attackStage == 1) {
		spikeAttack = true;

		LongAttackSprite.setTexture(reaperBossCrystalSpikeTex);

		LongAttackSprite.setOrigin(64, 64);

		LongAttackSprite.setPosition(player.position.x + rand() % 100, player.position.y + rand() % 100);
	}
	if (attackStage < 2) {
		LongAttackSprite.setTextureRect(sf::IntRect(reaperBossCrystalSpike[0]));

		attackStage += 5 * DeltaTime;
		renderWindow.draw(LongAttackSprite);
	}
	else if (attackStage < 3) {
		LongAttackSprite.setTextureRect(sf::IntRect(reaperBossCrystalSpike[1]));
		attackStage += 5 * DeltaTime;
		renderWindow.draw(LongAttackSprite);
	}
	else if (attackStage < 4) {
		LongAttackSprite.setTextureRect(sf::IntRect(reaperBossCrystalSpike[2]));
		attackStage += 5 * DeltaTime;
		renderWindow.draw(LongAttackSprite);
	}
	else if (attackStage < 5) {
		LongAttackSprite.setTextureRect(sf::IntRect(reaperBossCrystalSpike[3]));
		attackStage += 5 * DeltaTime;
		renderWindow.draw(LongAttackSprite);

		if (!player.hit) {
			if (LongAttackSprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
				player.currentHealth -= 15;
				player.hit = true;
			}
		}
	}
	else if (attackStage < 6) {
		LongAttackSprite.setTextureRect(sf::IntRect(reaperBossCrystalSpike[4]));
		attackStage += 10 * DeltaTime;
		renderWindow.draw(LongAttackSprite);
	}
	else if (attackStage >= 6) {
		attackStage = 1;
		player.hit = false;
		spikeAttack = false;
		LongAttackTime.restart();
	}
}

void ReaperBoss::reaperBossBeam() {

	if (!reaperBossBeamUsed) {
		LongAttackSprite.setTexture(reaperBossBeamTex);

		LongAttackSprite.setOrigin(64, 64);

		LongAttackSprite.setPosition(player.position.x + rand() % 150 + 50, player.position.y + rand() % 150 + 50);
	}

	reaperBossBeamUsed = true;

	if (LongAttackAnimation.getElapsedTime().asSeconds() > 0.3) {
		if (reaperBossBeamInt < 2) {
			reaperBossBeamInt += 1;
		}
		else {
			reaperBossBeamInt = 0;
		}
		LongAttackAnimation.restart();
	}

	sf::Vector2f movement(0, 0);

	float BeamSpeed = DeltaTime * 160;

	sf::Vector2f beamPosition;

	beamPosition = LongAttackSprite.getPosition();

	if (beamPosition.x > player.position.x) {
		movement.x -= BeamSpeed;
	}
	if (beamPosition.y < player.position.y) {
		movement.y += BeamSpeed;
	}
	if (beamPosition.x < player.position.x) {
		movement.x += BeamSpeed;
	}
	if (beamPosition.y > player.position.y) {
		movement.y -= BeamSpeed;
	}

	LongAttackSprite.setTextureRect(sf::IntRect(reaperBossBeamRect[reaperBossBeamInt]));

	LongAttackSprite.move(movement);

	renderWindow.draw(LongAttackSprite);

	if (reaperBossBeamInt == 0) {
		if (!player.hit) {
			if (LongAttackSprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
				player.currentHealth -= 5;
				player.hit = true;
			}
		}
	}

	if (reaperBossBeamInt == 1) {
		player.hit = false;
	}

	attackStage += DeltaTime;

	if (attackStage >= 10) {
		player.hit = false;
		attackStage = 1;
		reaperBossBeamUsed = false;
		LongAttackTime.restart();
	}
}

void ReaperBoss::OrbAttack() {
	if (orbs.size() < 3) {
		std::unique_ptr<Spheres> newOrb(new Spheres(renderWindow, player, DeltaTime, position));
		orbs.push_back(std::move(newOrb));

		attackStage += 1;

		orbsAttacking = true;
	}

	for (int i = 0; i < orbs.size(); i++) {
		orbs.at(i)->Follow();
		if (!orbs.at(i)->alive) {
			orbs.erase(orbs.begin() + i);
		}
	}

	if (orbs.size() <= 0 || LongAttackAnimation.getElapsedTime().asSeconds() >= 10) {
		attackStage = 1;
		orbsAttacking = false;
		LongAttackTime.restart();
	}
}

void ReaperBoss::DoShortAttack()
{
	sprite.setTexture(reaperBossSlashTex);
	attacking = true;
	spikeAttack = false;
	reaperBossBeamUsed = false;
	orbsAttacking = false;

	if (clock.getElapsedTime().asSeconds() > 0.10)
	{
		if (reaperBossSkinInt < 4)
		{
			reaperBossSkinInt += 1;
		}
		else if((!reaperBossSkinInt < 4))
		{
			reaperBossSkinInt = 0;
			int damage = (strength / 2);
			player.currentHealth -= damage;
			std::cout << damage;
		}
		/*if (clock.getElapsedTime().asSeconds() > 1) {
			int damage = (strength / 2);
			player.currentHealth -= damage;
			std::cout << damage;
		}*/
		clock.restart();
		
	}

	sf::Vector2f movement(0, 0);

}

void ReaperBoss::DoLongAttack()
{
	sprite.setTexture(reaperBossSummonTex);
	attacking = true;

		if (clock.getElapsedTime().asSeconds() > 0.15)
		{
			if (reaperBossSkinInt < 4)
			{
				reaperBossSkinInt += 1;
			}
			else
			{
				reaperBossSkinInt = 0;
			}
			clock.restart();
		}

		sf::Vector2f movement(0, 0);

		if (attackTime.getElapsedTime().asSeconds() > 2)
		{
			attackTime.restart();
		}

	int attackType = (rand() % 3 + 1);

	if (reaperBossBeamUsed) {
		reaperBossBeam();
	}
	else if (spikeAttack) {
		crystalSpike();
	}
	else if (orbsAttacking) {
		OrbAttack();
	}
	else if (LongAttackTime.getElapsedTime().asSeconds() > 0.5) {
		switch (attackType) {
		case 1:
			crystalSpike();
			break;
		case 2:
			reaperBossBeam();
			break;
		case 3:
			OrbAttack();
			break;
		}
	}
}

void ReaperBoss::move()
{
	sf::Vector2f movement(0, 0);

	float deltaSpeed = 200 * DeltaTime;

	if (position.x > player.position.x + 50) {
		movement.x -= deltaSpeed;
	}
	if (position.x < player.position.x - 50) {
		movement.x += deltaSpeed;
	}
	if (position.y > player.position.y + 20) {
		movement.y -= deltaSpeed;
	}
	if (position.y < player.position.y + 40) {
		movement.y += deltaSpeed;
	}

	sprite.move(movement);

	if (DoesCollide()) // if we collide with something
	{
		sprite.move(movement.x * -1, movement.y);

		if (DoesCollide()) // if we collide with something
		{
			sprite.move(movement.x, movement.y * -1);
		}
	}

	if (DoesCollide()) // if we collide with something
		{
			// undo the movement we just applied
		sprite.move(movement.x * -1, movement.y * -1);
	}
}

float GetDistance(sf::Vector2f a, sf::Vector2f b) {
	float deltaX = a.x - b.x;
	float deltaY = a.y - b.y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);

}

void ReaperBoss::attack()
{
	/*	if (position.x > player.position.x - 50 && position.x < player.position.x + 50 && position.y > player.position.y - 41 && position.y < player.position.y + 41)*/

	if (GetDistance(position, player.position) < 175)
	{
		move();
		DoShortAttack();
	}
	else if (GetDistance(position, player.position) < 600)
	{
		DoLongAttack();
	}
	else if (GetDistance(position, player.position) < 1000)
	{
		attacking = false;
		move();
	}
	else {
		attacking = false;
	}
}

void ReaperBoss::Update()
{
	if (alive)
	{
		if (currentHealth <= 0) 
		{
			alive = false;
		}

		position = sprite.getPosition();

		healthBar.setPosition(position + sf::Vector2f(-96, 96));
		int healthBarPercentage = 192 * currentHealth / maxHealth;
		healthBar.setSize(sf::Vector2f(healthBarPercentage, healthBar.getSize().y));
		renderWindow.draw(healthBar);

		attack();

				if (!attacking)
				{
					sprite.setTexture(reaperBossIdleTex);
				}

				if (clock.getElapsedTime().asSeconds() > 0.5)
				{
					if (reaperBossSkinInt < 3)
					{
						reaperBossSkinInt += 1;
					}
					else
					{
						reaperBossSkinInt = 0;
					}
					clock.restart();
				}
	}


	sprite.setTextureRect(sf::IntRect(reaperBossSkin[reaperBossSkinInt]));

	renderWindow.draw(sprite);
	
}