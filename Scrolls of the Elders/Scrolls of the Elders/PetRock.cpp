#include "PetRock.h"



PetRock::PetRock(sf::RenderWindow& renderWindow, sf::Texture& petRockTex, Character& player) : renderWindow(renderWindow), petRockTex(petRockTex), player(player)
{

	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	
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
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 800) {
		
		//float deltaDistance = speed *DeltaTime; // the amout of pixels to move per second in one axis

		sf::Vector2f movement(0, 0);

			if (petRockPos.x > player.position.x+50 ) {
				movement.x -= .1;
			}
			if (petRockPos.x < player.position.x-50) {
				movement.x += .1;
			}
			if (petRockPos.y > player.position.y+20) {
				movement.y -= 0.1;
			}
			if (petRockPos.y < player.position.y+40) {
				movement.y += 0.1;
			}
			
			sprite.move(movement);

			petRockPos = sprite.getPosition();
		
	}
}

void PetRock::attack() {

	if (petRockPos.x > player.position.x-50 && petRockPos.x < player.position.x+50 && petRockPos.y > player.position.y && petRockPos.y < player.position.y+41) {
		sf::Vector2f movement(0, 0);
		
		player.currentHealth -= 1;

	}
}

void PetRock::Update() {
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

