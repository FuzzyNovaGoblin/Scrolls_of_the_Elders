#include "Player.h"



Player::Player()
{
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
