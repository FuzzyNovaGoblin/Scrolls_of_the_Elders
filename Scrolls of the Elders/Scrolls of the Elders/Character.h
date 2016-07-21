#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>


using namespace std;

class Character
{
public:
	Character();

	Character(string inputName, string inputDescription, int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance);

	~Character();

	//Text Based Data

	string name; //Duh... it's a name
	string description; //A description, you know, for when you hover your mouse over them
	
	//Stats

	int health; //Starting Health for Player is 100
	int mana; //Starting Mana for Player is 100
	int gold; //5 Gold for Bread
	int strength; //Physical Damage + Ability to Use Armor / Weapons
	int intelligence; //Magical Damage + Ability to Use Spells
	int dexterity; //Speed and Ranged Damage
	int defense; //Physical Resist
	int constitution; //Magical Resist
	int endurance; //Stamina + How much you can carry
	int level; //Stats scale with level, MENU TO CHOOSE?

	//Functions
	virtual void attack(Character target); //Attack Function (Sword)
	virtual void magicSFML(); //Actuator and Animation for Attack (Magic)
	virtual void magic(); //Attack Function (Magic)
	virtual void rangedSFML(); //Actuator and Animation for Attack (Ranged)
	virtual void ranged(); //Attack Function (Ranged)
	virtual void heal();
	void update();
	virtual void move();
	virtual void openDoor();
	virtual void talk();
	virtual void trade();
	virtual void openChest();
};

