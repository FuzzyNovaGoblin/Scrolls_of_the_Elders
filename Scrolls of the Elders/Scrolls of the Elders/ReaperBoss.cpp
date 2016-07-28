#include "ReaperBoss.h"

int GetDistance(sf::Vector2f a, sf::Vector2f b);

ReaperBoss::ReaperBoss(int inputHealth, sf::RenderWindow& renderWindow, Character& player, float &DeltaTime, Map &map) : Character(DeltaTime, map), renderWindow(renderWindow), player(player)
{
	reaperBossIdleTex.loadFromFile("resources/character/Reaper Boss-Idle.png");
	reaperBossSlashTex.loadFromFile("resources/character/Reaper Boss-Attack.png");
	reaperBossSummonTex.loadFromFile("resources/character/Reaper Boss-Magic.png");
	reaperBossTeleportTex.loadFromFile("resources/character/Reaper Boss-Teleport.png");
	reaperBossSkin[0] = sf::IntRect(0, 0, 192, 192);
	reaperBossSkin[1] = sf::IntRect(192, 0, 192, 192);
	reaperBossSkin[2] = sf::IntRect(0, 192, 192, 192);
	reaperBossSkin[3] = sf::IntRect(192, 192, 192, 192);
	reaperBossSkin[4] = sf::IntRect(0, 384, 192, 192);

	sprite.setOrigin(96, 96);

	currentHealth = inputHealth;

	strength = 10;

	hit = false;

	float tempX = rand() % 500 + 151;
	float tempY = rand() % 500 + 151;

	reaperBossPos.x = tempX;
	reaperBossPos.y = tempY;

	sprite.setPosition(reaperBossPos.x, reaperBossPos.y);

	sprite.setTexture(reaperBossIdleTex);

	timer = clock.getElapsedTime().asSeconds();

}

void ReaperBoss::DoShortAttack()
{
	sprite.setTexture(reaperBossSlashTex);
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

			if (attackTime.getElapsedTime().asSeconds() > 1) 
			{
				int damage = (strength / 2) + (rand() % strength + 1);
				player.currentHealth -= damage;

				attackTime.restart();
			}
				
		else
		{
			attacking = false;
		}
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

		if (attackTime.getElapsedTime().asSeconds() > 1)
		{
			

			attackTime.restart();
		}

		else
		{
			attacking = false;
		}
	//(rand() % 4 + 0);
}

void ReaperBoss::move()
	{
	if(GetDistance(position, player.position) < 4000)
	{
		sf::Vector2f movement(0, 0);

		float deltaSpeed = 300 * DeltaTime;

		if (reaperBossPos.x > player.position.x + 50) {
			movement.x -= deltaSpeed;
		}
		if (reaperBossPos.x < player.position.x - 50) {
			movement.x += deltaSpeed;
		}
		if (reaperBossPos.y > player.position.y + 20) {
			movement.y -= deltaSpeed;
		}
		if (reaperBossPos.y < player.position.y + 40) {
			movement.y += deltaSpeed;
		}

		sprite.move(movement);

		if (DoesCollide()) // if we collide with something
		{
			// undo the movement we just applied
			sprite.move(movement.x * -1, movement.y * -1);
		}

		reaperBossPos = sprite.getPosition();
	}
}

int GetDistance(sf::Vector2f a, sf::Vector2f b) {
	int deltaX = a.x - b.x;
	int deltaY = a.y - b.y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);

}

void ReaperBoss::attack()
{
		if (reaperBossPos.x > player.position.x - 50 && reaperBossPos.x < player.position.x + 50 && reaperBossPos.y > player.position.y - 41 && reaperBossPos.y < player.position.y + 41)
		{
			DoShortAttack();
		}

		//else if (GetDistance(position, player.position) > 100 < 800)
		//{
		//	DoLongAttack();
		//}
		
}

void ReaperBoss::Update()
{
	if (alive)
	{
	if (currentHealth <= 0) 
	{
		alive = false;
	}
	attack();
	move();

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