#include "PetRock.h"



PetRock::PetRock(sf::RenderWindow& renderWindow)
{

	sf::IntRect petRockSkin[3];
	petRockSkin[0] = sf::IntRect(0, 0, 20, 14);
	petRockSkin[1] = sf::IntRect(14, 0, 20, 14);
	petRockSkin[2] = sf::IntRect(28, 0, 20, 14);
	sf::Texture petRockTex;
	petRockTex.loadFromFile("resources/character/petRock.png");
	
	petRockSprite.setTexture(petRockTex);
	petRockSprite.setTextureRect(sf::IntRect(petRockSkin[petRockSkinInt]));
	sf::Clock clock;

	timer = clock.getElapsedTime().asSeconds();

	if (timer > 0.1f)
	{
		if (petRockSkinInt == 0)
			petRockSkinInt = 1;
		else
			petRockSkinInt = 0;
		clock.restart();
	}
	
}


PetRock::~PetRock()
{
}



void PetRock::updatePetRock() {
	

	renderWindow.draw(petRockSprite);
	
}

