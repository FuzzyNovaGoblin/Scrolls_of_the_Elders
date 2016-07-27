#include "Character.h"

Character::Character(float& DeltaTime, Map &map) : DeltaTime(DeltaTime), map(map)
{
	name = "Default Name";
	description = "If you see this, there is a bug, please submit a bug report.";
	maxHealth = 100;
	currentHealth = maxHealth;
	mana = 100;
	gold = 0;
	strength = 2;
	intelligence = 1;
	dexterity = 1;
	defense = 1;
	constitution = 1;
	endurance = 1;
}

Character::Character(string inputName, string inputDescription, int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, float& DeltaTime, Map &map) : DeltaTime(DeltaTime), map(map)
{
	alive = true;
	name = inputName;
	description = inputDescription;
	maxHealth = inputHealth;
	currentHealth = maxHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;
}


void Character::Update() {
	cout << "This is the Character's Update" << endl;
}

bool Character::DoesCollide() {
	for (int i = 0; i < map.tiles.size(); i++) {
		// if we collide with a prop
		if (sprite.getGlobalBounds().intersects(map.tiles.at(i).graphic.getGlobalBounds())) {
			if (map.tiles.at(i).hasCollider) {
				return true; // only support colliding with one prop at a time, so end function
							 // after the first succesful collision
			}
		}
	}
	// we succesffuly checked collision against all the props in the scene
	// we hit nothing so return false: we do not collide
	return false;
}