#include "Character.h"



Character::Character()
{
	name = "Default Name";
	description = "If you see this, there is a bug, please submit a bug report.";
	maxHealth = 100;
	mana = 100;
	gold = 0;
	strength = 1;
	intelligence = 1;
	dexterity = 1;
	defense = 1;
	constitution = 1;
	endurance = 1;
}

Character::Character(string inputName, string inputDescription, int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::Texture inputTexture, sf::Sprite inputSprite)
{
	name = inputName;
	description = inputDescription;
	maxHealth = inputHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;

	//Do texture stuff

	//End of texture stuff

	characterSprite = inputSprite;
}


Character::~Character()
{
}

