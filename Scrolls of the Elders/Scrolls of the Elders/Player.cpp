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

Player::Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance)
{
	//name = inputName;
	//description = inputDescription;
	health = inputHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;

	//characterSprite = inputSprite;
	sf::Texture inputTexture;
	sf::Sprite inputSprite;
	//Do texture stuff
	
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

	//Movement checks here

	sf::Vector2f movement(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		movement.y -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movement.y += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += 1;
	}

	characterSprite.move(movement);
}