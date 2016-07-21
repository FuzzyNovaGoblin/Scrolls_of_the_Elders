#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
	Item();
	~Item();

	//Text Based Data
	string name; //Name of the Item
	string description; //Description of the Item
	
	//Stats
	int weight; //Weight of the Item
	int value; //Worth in Gold
};

