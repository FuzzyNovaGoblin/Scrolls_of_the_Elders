#include "PetRock.h"



PetRock::PetRock(sf::RenderWindow& renderWindow) : renderWindow(renderWindow)
{

	
	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	petRockTex.loadFromFile("resources/character/petRock.png");
	
	petRockPos.x = 300;
	petRockPos.y = 300; 

	petRockSprite.setPosition(petRockPos.x, petRockPos.y);

	petRockSprite.setTexture(petRockTex);
	

	

	timer = clock.getElapsedTime().asSeconds();

}


PetRock::~PetRock()
{
}

void PetRock::move(Player &player) {
	if (petRockPos.x > player.playerPos.x) {
		petRockPos.x -= .1;
	}
	 if (petRockPos.x < player.playerPos.x) {
		petRockPos.x += .1;
	}
	 if (petRockPos.y > player.playerPos.y) {
		petRockPos.y -= .1;
	}
	 if (petRockPos.y < player.playerPos.y) {
		petRockPos.y += .1;
	}
}

void PetRock::updatePetRock(Player &player) {
	move(player);
	petRockSprite.setPosition(petRockPos.x, petRockPos.y);

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

