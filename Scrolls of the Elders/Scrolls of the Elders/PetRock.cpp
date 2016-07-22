#include "PetRock.h"



PetRock::PetRock(sf::RenderWindow& renderWindow) : renderWindow(renderWindow)
{

	
	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	petRockTex.loadFromFile("resources/character/petRock.png");
	
	

	petRockSprite.setPosition(petRockPos.x, petRockPos.y);

	petRockSprite.setTexture(petRockTex);
	

	

	timer = clock.getElapsedTime().asSeconds();

/*	if (timer > 0.1f)
	{
		if (petRockSkinInt == 0)
			petRockSkinInt = 1;
		else
			petRockSkinInt = 0;
		clock.restart();
	}
	*/
}


PetRock::~PetRock()
{
}

void PetRock::move() {
	if (petRockPos.x > playerX) {

	}
}

void PetRock::updatePetRock(Player &player) {

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

