#include "Player.h"



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
		
		target.health -= currentDamage;

	}
	else {
		//Yo Grant, here is where you can tell it to do a normal display

		//This is my code, no touch...

		target.health -= currentDamage;

	}
}

void Player::equipMelee(MeleeWeapon meleeWeapon) {
	rightHandWeapon = meleeWeapon;
}

void Player::update(sf::Sprite playerSprite) {
	
	//Do all other checks here:

	//Movement checks here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerSprite.move(0, 1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerSprite.move(0, -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		playerSprite.move(1, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		playerSprite.move(-1, 0);
	}
}