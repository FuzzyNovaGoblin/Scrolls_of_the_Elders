#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character
{
public:
	Character();
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
};

