#include "PetRock.h"



PetRock::PetRock(int inputHealth, sf::RenderWindow& renderWindow, sf::Texture& petRockTex, Character& player, float& DeltaTime, Map &map) : Character(DeltaTime, map), renderWindow(renderWindow), petRockTex(petRockTex), player(player)
{

	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	currentHealth = inputHealth;

	strength = 4;

	hit = false;

	float tempX = rand() % 2000 + 0;
	float tempY = rand() % 2000 + 0;

	position.x = tempX;
	position.y = tempY; 

	sprite.setPosition(position.x, position.y);

	sprite.setTexture(petRockTex);
	
	timer = clock.getElapsedTime().asSeconds();
	sprite.setOrigin(20, 14);

}


void PetRock::move() {
	int distanceX = position.x - player.position.x;
	int distanceY = position.y - player.position.y;
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 500) {
		
		//float deltaDistance = speed *DeltaTime; // the amout of pixels to move per second in one axis

		sf::Vector2f movement(0, 0);

		float deltaSpeed = DeltaTime * 300;

			if (position.x > player.position.x+50 ) {
				movement.x -= deltaSpeed;
			}
			if (position.y < player.position.y + 40) {
				movement.y += deltaSpeed;
			}
			if (position.x < player.position.x-50) {
				movement.x += deltaSpeed;
			}
			if (position.y > player.position.y+20) {
				movement.y -= deltaSpeed;
			}

			sprite.move(movement);
			//if you want to colide
			//-----------------------------------------------------
			//if (DoesCollide()) // if we collide with something
			//{
			//	// undo the movement we just applied
			//	sprite.move(movement.x * -1, movement.y * -1);
			//}
			//-----------------------------------------------------

			position = sprite.getPosition();
		
	}
}

void PetRock::attack() {

	if (position.x > player.position.x - 51 && position.x < player.position.x + 51 && position.y > player.position.y && position.y < player.position.y + 42) {
		sf::Vector2f movement(0, 0);

		if (attackTime.getElapsedTime().asSeconds() > 1) {
	
			int damage = (strength / 2) + (rand() % strength + 1);
			player.currentHealth -= damage;

			attackTime.restart();

		}

	}
}

void PetRock::Update() {
	if (alive) {
		
		if (currentHealth <= 0) {
			alive = false;
		}
		attack();
		move();

		if (clock.getElapsedTime().asSeconds() > 0.5) {
			if (petRockSkinInt == 0) {
				petRockSkinInt = 1;
			}
			else {
				petRockSkinInt = 0;
			}
			clock.restart();
		}

		sprite.setTextureRect(sf::IntRect(petRockSkin[petRockSkinInt]));

		renderWindow.draw(sprite);
	}


}