#include "PetRock.h"



PetRock::PetRock()
{
	sf::Texture playerTex;

	playerTex.loadFromFile("resources/character/petRock.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	playerSprite.setTextureRect(sf::IntRect(2, 2, 3, 4));

	
}


PetRock::~PetRock()
{
}

void PetRock::updatePetRock() {
	
}