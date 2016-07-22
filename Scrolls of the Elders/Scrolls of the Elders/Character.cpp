#include "Character.h"



Character::Character()
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

Character::Character(string inputName, string inputDescription, int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance)
{
	name = inputName;
	description = inputDescription;
	health = inputHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;
}


Character::~Character()
{
}

void Character::attack(Character target) {

} //Attack Function (Sword)
void Character::magicSFML() {

} //Actuator and Animation for Attack (Magic)
void Character::magic() {

} //Attack Function(Magic)
void Character::rangedSFML() {

} //Actuator and Animation for Attack (Ranged)
void Character::ranged() {

} //Attack Function (Ranged)
void Character::heal() {

}
void Character::move() {

}
void Character::openDoor() {

}
void Character::talk() {

}
void Character::trade() {

}
void Character::openChest() {

}