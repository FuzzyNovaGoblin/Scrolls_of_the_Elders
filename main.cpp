#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "player.h"
#include "enemy.h"

using namespace std;

void delayScroll(int delayMS, int lineCount);
character *generateEnemy();
void encounterEnemy(character *player, character *enemy);
void fightDecisions(character *player);
void randomScene();
void delayScroll(int delayMS, int lineCount) {
	for (int i = 0; i < lineCount; i++) {
		cout << "" << endl;
	}
}

character *generateEnemy(int playerLevel) {
	character *e = new enemy("Skelington", "A reanimated skelington of a long dead warrior.", playerLevel);
	e->setStats(1);
	return e;
}

void fightDecisions(character *player1) {
	if (player1->isAlive()) {
		character *anEnemy = generateEnemy(player1->level);
		string option = "";
		cout << "You encounter " << anEnemy->name << ". " << anEnemy->description << endl;
		cout << "1. Fight" << endl;
		cout << "2. Run" << endl;
		cout << "> ";
		cin >> option;

		if (option == "Fight" || option == "fight") {
			encounterEnemy(player1, anEnemy);
		}
		else {
			cout << "You run away." << endl;
			fightDecisions(player1);
		}
	}
	else {
		cout << "You are dead..." << endl;
	}
}

void encounterEnemy(character *player, character *enemy) {
	while (player->isAlive() && enemy->isAlive()) {
		player->fight(enemy);
		enemy->fight(player);
		delayScroll(10, 1);
	}
	fightDecisions(player);
}

void randomScene() {
	int sceneNumber = rand() % 5 + 1;

}

int main() {
	srand(time(NULL));
	string intro =
		"          _____          \n"
        "      __ /__    \\__     \n"
        "   _ /      \\    __\\   \n"
        "  /          \\__ /  \\  \n"
        " |   O          O    |    \n"
        " |      ______      /    \n"
        "  \\     \\____/     /   \n"
        "   \\______________/     \n"
 
        "  Elders of the Scrolls";

	cout << intro << endl;

	string playerName;
	cout << "Enter your Name " << endl;
	cout << "> ";
	cin >> playerName;
	cout << "The time is dawn, you wander the world and encounter beasts of plenty." << endl;
	this_thread::sleep_for(chrono::microseconds(1000));
	delayScroll(10, 30);
	
	character *myPlayer = new player(playerName, "The Fated One, Born of Dragons.", 1);
	
	randomScene();

	fightDecisions(myPlayer);

	myPlayer->leftHandWeapon
}