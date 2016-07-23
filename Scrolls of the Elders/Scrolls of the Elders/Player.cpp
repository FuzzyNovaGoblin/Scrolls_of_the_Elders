#include "Player.h"


/*
Player::Player()
{
	name = "Default Name";
	description = "If you see this, there is a bug, please submit a bug report.";
	health = 100;
	mana = 100;
	gold = 0;
	strength = 1;
	intelligence = 1;
	dexterity = 1;
	defense = 1;
	constitution = 1;
	endurance = 1;
}
*/


Player::Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow) : renderWindow(renderWindow)
{
	health = inputHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;

	//Do texture stuff
	playerTex.loadFromFile("resources/character/player-Idle.png");
	playerSkin[0] = sf::IntRect(0, 0, 100, 130);
	playerSkin[1] = sf::IntRect(130, 0, 100, 130);
	playerSkin[2] = sf::IntRect(0, 130, 100, 130);
	playerSkin[3] = sf::IntRect(100, 130, 100, 130);


	playerSprite.setTexture(playerTex);
	playerSprite.setOrigin(50, 65);
	//End of texture stuff
}

Player::~Player()
{
}

void Player::attackSFML() {

}

void Player::attack(Character target) {
	int currentDamage = (strength / 2) + (rand() % strength);
	currentDamage += rightHandWeapon.damage;
	if (currentDamage > strength) {
		//Yo Grant, here is where you can tell it to do critical display

		//This is my code, no touch...
		
		target.currentHealth -= currentDamage;

	}
	else {
		//Yo Grant, here is where you can tell it to do a normal display

		//This is my code, no touch...

		target.currentHealth -= currentDamage;

	}
}

void Player::equipMelee(MeleeWeapon meleeWeapon) {
	rightHandWeapon = meleeWeapon;
}

void Player::update() {
	
	//Do all other checks here:
	playerPos = characterSprite.getPosition();
	//Movement checks here

	sf::Vector2f movement(0, 0);

	playerSprite.setPosition(playerPos.x, playerPos.y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement.y -= 0.2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement.y += 0.2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x -= 0.2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += 0.2;
	}

	if (clock.getElapsedTime().asSeconds() > 0.5) {
		if (playerSkinInt == 0) {
			playerSkinInt = 1;
		}
		else if (playerSkinInt == 1){
			playerSkinInt = 2;
		}
		else if (playerSkinInt == 2) {
			playerSkinInt = 3;
		}
		if (playerSkinInt == 3) {
			playerSkinInt = 0;
		}
		clock.restart();
	}

	characterSprite.move(movement);
	playerSprite.setTextureRect(sf::IntRect(playerSkin[playerSkinInt]));
	renderWindow.draw(playerSprite);
}