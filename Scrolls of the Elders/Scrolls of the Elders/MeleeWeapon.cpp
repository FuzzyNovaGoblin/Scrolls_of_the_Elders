#include "MeleeWeapon.h"



MeleeWeapon::MeleeWeapon()
{
	name = "Default Weapon";
	description = "Default Description";
	weight = 0;
	value = 0;
	damage = 0;
}

MeleeWeapon::MeleeWeapon(string inputName, string inputDescription, int inputWeight, int inputValue, int inputDamage, string inputFilename)
{
	name = inputName;
	description = inputDescription;
	weight = inputWeight;
	value = inputValue;
	damage = inputDamage;
	MeleeWeaponTexture.loadFromFile("resources/items/" + inputFilename);
	MeleeWeaponSprite.setTexture(MeleeWeaponTexture);
	MeleeWeaponSprite.setOrigin(MeleeWeaponSprite.getGlobalBounds().width / 2, MeleeWeaponSprite.getGlobalBounds().height);
}


MeleeWeapon::~MeleeWeapon()
{
}