#include "PetRock.h"



PetRock::PetRock(sf::RenderWindow& renderWindow, sf::Texture& petRockTex) : renderWindow(renderWindow), petRockTex(petRockTex)
{

	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	
	float tempX = rand() % 4000 + 1;
	float tempY = rand() % 3000 + 1;

	petRockPos.x = tempX;
	petRockPos.y = tempY; 

	petRockSprite.setPosition(petRockPos.x, petRockPos.y);

	petRockSprite.setTexture(petRockTex);
	

	

	timer = clock.getElapsedTime().asSeconds();

}


PetRock::~PetRock()
{
}

void PetRock::move(Player &player) {
	int distanceX = petRockPos.x - player.playerPos.x;
	int distanceY = petRockPos.y - player.playerPos.y;
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 800) {
		
		//float deltaDistance = speed *DeltaTime; // the amout of pixels to move per second in one axis

		sf::Vector2f movement(0, 0);

			if (petRockPos.x > player.playerPos.x+50 ) {
				movement.x -= .1;
			}
			if (petRockPos.x < player.playerPos.x-50) {
				movement.x += .1;
			}
			if (petRockPos.y > player.playerPos.y+20) {
				movement.y -= 0.1;
			}
			if (petRockPos.y < player.playerPos.y+40) {
				movement.y += 0.1;
			}
			
			petRockSprite.move(movement);

			petRockPos = petRockSprite.getPosition();
		
	}
}

void PetRock::attack(Player &player) {

	if (petRockPos.x > player.playerPos.x-50 && petRockPos.x < player.playerPos.x+50 && petRockPos.y > player.playerPos.y && petRockPos.y < player.playerPos.y+41) {
		sf::Vector2f movement(0, 0);
		
		player.currentHealth -= 1;

	}
}

void PetRock::updatePetRock(Player &player) {
	attack(player);
	move(player);	

	

	if (clock.getElapsedTime().asSeconds() > 0.5) {
		if (petRockSkinInt == 0) {
			petRockSkinInt = 1;
		}
		else {
			petRockSkinInt = 0;
		}
		clock.restart();
	}

	petRockSprite.setTextureRect(sf::IntRect(petRockSkin[petRockSkinInt]));
	renderWindow.draw(petRockSprite);
}

