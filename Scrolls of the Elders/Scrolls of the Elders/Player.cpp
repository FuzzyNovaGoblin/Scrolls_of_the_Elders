#include "Player.h"


/*
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
*/


Player::Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow) : renderWindow(renderWindow)
{
	alive = true;
	maxHealth = inputHealth;
	mana = inputMana;
	gold = inputGold;
	strength = inputStrength;
	intelligence = inputIntelligence;
	dexterity = inputDexterity;
	defense = inputDefense;
	constitution = inputConstitution;
	endurance = inputEndurance;
	currentHealth = maxHealth;
	//Do texture stuff
	playerIdleTex.loadFromFile("resources/character/player-Idle.png");
	playerForwardTex.loadFromFile("resources/character/Player-Walking.png");
	playerRightTex.loadFromFile("resources/character/Player-Walking-Right.png");
	playerLeftTex.loadFromFile("resources/character/Player-Walking-Left.png");
	playerBackTex.loadFromFile("resources/character/Player-Walking-Up.png");
	playerSkin[0] = sf::IntRect(0, 0, 128, 128);
	playerSkin[1] = sf::IntRect(128, 0, 128, 128);
	playerSkin[2] = sf::IntRect(0, 128, 128, 128);
	playerSkin[3] = sf::IntRect(128, 128, 128, 128);


	
	playerSprite.setOrigin(50, 65);
	//End of texture stuff
}

Player::~Player()
{
}

void Player::attackSFML() {
	sf::Vector2i localPosition = sf::Mouse::getPosition(renderWindow);
	sf::Vector2f worldPosition = renderWindow.mapPixelToCoords(localPosition);
	double angle;
	angle = atan2(worldPosition.y - playerPos.y, worldPosition.x - playerPos.x) * 180 / PI;
	if (angle < 0) {
		angle = angle * -1;
	}
	else if (angle > 0) {
		angle = 360 - angle;
	}
	cout << angle << endl;
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

void Player::update()
{
	
	if (alive) {
		//Do all other checks here:
		playerPos = characterSprite.getPosition();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			attackSFML();
		}
		//Movement checks here

		//float testAnimSpeed = 0.5f;

		sf::Vector2f movement(0, 0);

		playerSprite.setPosition(playerPos.x, playerPos.y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			movement.y += 0.5;
			playerSprite.setTexture(playerForwardTex);
			animationSpeed = 0.2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement.x -= 0.5;
			playerSprite.setTexture(playerLeftTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement.x += 0.5;
			playerSprite.setTexture(playerRightTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			movement.y -= 0.5;
			playerSprite.setTexture(playerBackTex);
			animationSpeed = 0.2;
		}


		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerSprite.setTexture(playerIdleTex);
			animationSpeed = 0.5;
		}



		if (clock.getElapsedTime().asSeconds() > animationSpeed) {
			if (playerSkinInt == 0) {
				playerSkinInt = 1;
			}
			else if (playerSkinInt == 1) {
				playerSkinInt = 2;
			}
			else if (playerSkinInt == 2) {
				playerSkinInt = 3;
			}
			else {
				playerSkinInt = 0;
			}
			clock.restart();
		}
		
		if (currentHealth <= 0) {
			alive = false;
		}

		characterSprite.move(movement);
		playerSprite.setTextureRect(sf::IntRect(playerSkin[playerSkinInt]));
		renderWindow.draw(playerSprite);
	}
	else {

	}
}