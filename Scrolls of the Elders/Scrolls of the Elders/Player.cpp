#include "Player.h"


Player::Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow, std::vector<std::unique_ptr<Character>>& petRockList) :renderWindow(renderWindow), petRockList(petRockList)
{
	asmanFont.loadFromFile("resources\font\ASMAN.ttf");

	score = 0;
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

	//Doing Health Text
	healthFont.loadFromFile("resources/font/Amatic-Bold.ttf");
	healthText.setFont(healthFont);
	healthText.setCharacterSize(72);
	healthText.setColor(sf::Color(196, 33, 33));

	healthText.setString("Health: " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth));

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


	
	sprite.setOrigin(50, 65);
	//End of texture stuff
}


void Player::attackSFML() {
	sf::Vector2i localPosition = sf::Mouse::getPosition(renderWindow);
	sf::Vector2f worldPosition = renderWindow.mapPixelToCoords(localPosition);
	double angle;
	angle = atan2(worldPosition.y - position.y, worldPosition.x - position.x) * 180 / PI;
	if (angle < 0) {
		angle = angle * -1;
	}
	else if (angle > 0) {
		angle = 360 - angle;
	}

	rightHandWeapon.MeleeWeaponSprite.setPosition(position.x-15, position.y+7);
	rightHandWeapon.MeleeWeaponSprite.setRotation(-angle+90);

	renderWindow.draw(rightHandWeapon.MeleeWeaponSprite);
	for (int i = 0; i < petRockList.size(); i++) {
		Character* ptr = petRockList.at(i).get();
		if (rightHandWeapon.MeleeWeaponSprite.getGlobalBounds().intersects((*ptr).sprite.getGlobalBounds())) {
			attack(*petRockList[i]);
		}
		}
}

void Player::attack(Character& target) {
	int currentDamage = (strength / 2) + (rand() % strength);
	currentDamage += rightHandWeapon.damage;
	if (currentDamage > strength) {
		//Yo Grant, here is where you can tell it to do critical display

		//This is my code, no touch...
		
		target.currentHealth -= currentDamage;
		if (target.currentHealth <= 0) {
			score += 1;
		}
	}
	else {
		//Yo Grant, here is where you can tell it to do a normal display

		//This is my code, no touch...

		target.currentHealth -= currentDamage;
		if (target.currentHealth <= 0) {
			score += 1;
		}
	}
}

void Player::equipMelee(MeleeWeapon meleeWeapon) {
	rightHandWeapon = meleeWeapon;
}

void Player::Update()
{
	
	if (alive) {
		//Do all other checks here:
		position = sprite.getPosition();
		score = 0;
		//Movement checks here

		//float testAnimSpeed = 0.5f;

		//Movement
		sf::Vector2f movement(0, 0);

		sprite.setPosition(position.x, position.y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			movement.y += 0.5;
			sprite.setTexture(playerForwardTex);
			animationSpeed = 0.2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement.x -= 0.5;
			sprite.setTexture(playerLeftTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement.x += 0.5;
			sprite.setTexture(playerRightTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			movement.y -= 0.5;
			sprite.setTexture(playerBackTex);
			animationSpeed = 0.2;
		}


		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sprite.setTexture(playerIdleTex);
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
		//End of Movement
		
		//Is alive check
		if (currentHealth <= 0) {
			alive = false;
		}
		//End of is Alive Check

		//Doing all texture stuff
		sprite.move(movement);
		sprite.setTextureRect(sf::IntRect(playerSkin[playerSkinInt]));
		renderWindow.draw(sprite);
		// End of all texture stuff

		//Doing Health Text
		healthText.setString("Health: " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth));
		healthText.setPosition(position.x-890, position.y-490);
		renderWindow.draw(healthText);
		//End of Health Text

		//Mouse Sensor
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			attackSFML();
		}
		//End of Mouse Sensor
	}
	else {
		scoreString = score;
		scoreText.setFont(asmanFont);
		scoreText.setString(scoreString);
		scoreText.setCharacterSize(24);
		scoreText.setColor(sf::Color::Red);
	}
}