#include "ReaperBoss.h"



ReaperBoss::ReaperBoss(int inputHealth, sf::RenderWindow& renderWindow, Character& player) : Character(DeltaTime), renderWindow(renderWindow), player(player)
{
	reaperBossIdleTex.loadFromFile("resources/character/Reaper Boss-Idle.png");
	reaperBossSlashTex.loadFromFile("resources/character/Reaper Boss-Attack.png");
	reaperBossSummonTex.loadFromFile("resources/character/Reaper Boss-Magic.png");
	reaperBossTeleportTex.loadFromFile("resources/character/Reaper Boss-Teleport.png");
	reaperBossSkin[0] = sf::IntRect(0, 0, 192, 192);
	reaperBossSkin[1] = sf::IntRect(192, 0, 384, 192);
	reaperBossSkin[2] = sf::IntRect(0, 192, 192, 384);
	reaperBossSkin[3] = sf::IntRect(192, 192, 384, 384);

	currentHealth = inputHealth;

	float tempX = rand() % 4000 + 1;
	float tempY = rand() % 3000 + 1;

	reaperBossPos.x = tempX;
	reaperBossPos.y = tempY;

	sprite.setPosition(reaperBossPos.x, reaperBossPos.y);

	sprite.setTexture(reaperBossIdleTex);

	timer = clock.getElapsedTime().asSeconds();

}

void ReaperBoss::move()
{
	int distanceX = reaperBossPos.x - player.position.x;
	int distanceY = reaperBossPos.y - player.position.y;
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 800)
	{
		sf::Vector2f movement(0, 0);

		if (reaperBossPos.x > player.position.x + 50) {
			movement.x -= .1;
		}
		if (reaperBossPos.x < player.position.x - 50) {
			movement.x += .1;
		}
		if (reaperBossPos.y > player.position.y + 20) {
			movement.y -= 0.1;
		}
		if (reaperBossPos.y < player.position.y + 40) {
			movement.y += 0.1;
		}

		sprite.move(movement);

		reaperBossPos = sprite.getPosition();
	}
}

void ReaperBoss::attack()
{
	if (reaperBossPos.x > player.position.x - 50 && reaperBossPos.x < player.position.x + 50 && reaperBossPos.y > player.position.y && reaperBossPos.y < player.position.y + 41) 
	{
			sf::Vector2f movement(0, 0);

			if (attackTime.getElapsedTime().asSeconds() > 1) {

				player.currentHealth -= 5;
				attackTime.restart();
			}
	}
}

void ReaperBoss::Update()
{
	if (currentHealth <= 0) 
	{
		alive = false;
	}
	attack();
	move();

	if (clock.getElapsedTime().asSeconds() > 0.5) 
	{
		if (reaperBossSkinInt == 0) 
		{
			reaperBossSkinInt = 1;
		}
		else 
		{
			reaperBossSkinInt = 0;
		}
		clock.restart();
	}

	sprite.setTextureRect(sf::IntRect(reaperBossSkin[reaperBossSkinInt]));

	renderWindow.draw(sprite);
}

ReaperBoss::~ReaperBoss()
{

}
