#include "PetRock.h"



PetRock::PetRock(int inputHealth, sf::RenderWindow& renderWindow, sf::Texture& petRockTex, Character& player, float& DeltaTime) : Character(DeltaTime), renderWindow(renderWindow), petRockTex(petRockTex), player(player)
{

	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	currentHealth = inputHealth;

	float tempX = rand() % 4000 + 1;
	float tempY = rand() % 3000 + 1;

	petRockPos.x = tempX;
	petRockPos.y = tempY; 

	sprite.setPosition(petRockPos.x, petRockPos.y);

	sprite.setTexture(petRockTex);
	
	timer = clock.getElapsedTime().asSeconds();

}


void PetRock::move() {
	int distanceX = petRockPos.x - player.position.x;
	int distanceY = petRockPos.y - player.position.y;
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 4000) {
		
		//float deltaDistance = speed *DeltaTime; // the amout of pixels to move per second in one axis

		sf::Vector2f movement(0, 0);

		float deltaSpeed = DeltaTime * 600;

			if (petRockPos.x > player.position.x+50 ) {
				movement.x -= deltaSpeed;
			}
			if (petRockPos.x < player.position.x-50) {
				movement.x += deltaSpeed;
			}
			if (petRockPos.y > player.position.y+20) {
				movement.y -= deltaSpeed;
			}
			if (petRockPos.y < player.position.y+40) {
				movement.y += deltaSpeed;
			}
			
			sprite.move(movement);

			petRockPos = sprite.getPosition();
		
	}
}

void PetRock::attack() {

	if (petRockPos.x > player.position.x - 51 && petRockPos.x < player.position.x + 51 && petRockPos.y > player.position.y && petRockPos.y < player.position.y + 42) {
		sf::Vector2f movement(0, 0);

		if (attackTime.getElapsedTime().asSeconds() > 1) {
	
			player.currentHealth -= 5;
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

