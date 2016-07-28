#include "Player.h"


Player::Player(int inputHealth, int inputMana, int inputGold, int inputStrength, int inputIntelligence, int inputDexterity, int inputDefense, int inputConstitution, int inputEndurance, sf::RenderWindow& renderWindow, std::vector<std::unique_ptr<Character>>& petRockList, float& DeltaTime, Map &map) : 
	
	Character("DefaultName" , "DefaultDescription", inputHealth, inputMana, inputGold, inputStrength, inputIntelligence, inputDexterity, inputDefense, inputConstitution, inputEndurance,  DeltaTime, map), renderWindow(renderWindow), petRockList(petRockList)
{
	asmanFont.loadFromFile("resources/font/ASMAN.ttf");

	score = 0;

	attackState = false;

	sprite.setPosition(450, 450);

	//Set the attack settings
	swingArc = 80;
	swingTime = 0.2;
	degreesPerSecond = swingArc / swingTime;
	//End of attack settings

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

	sprite.setPosition(300, 300);

	attacked = false;
	//End of texture stuff

	//Doing Health Text
	healthFont.loadFromFile("resources/font/Amatic-Bold.ttf");
	healthText.setFont(healthFont);
	healthText.setCharacterSize(72);
	healthText.setColor(sf::Color(196, 33, 33));

	healthText.setString("Health: " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth));
}


void Player::attackSFML(float angle) {
	rightHandWeapon.MeleeWeaponSprite.setPosition(position.x - 15, position.y + 7);
	if (stage < swingArc) {
		rightHandWeapon.MeleeWeaponSprite.setRotation(angle + (stage - 1));
		float deltaAngleChange;
		deltaAngleChange = DeltaTime * degreesPerSecond;
		stage += deltaAngleChange;
		renderWindow.draw(rightHandWeapon.MeleeWeaponSprite);
		for (int i = 0; i < petRockList.size(); i++) {
			Character* ptr = petRockList.at(i).get();


			//----------------This is how we can change the hitBox------------------------
			//sf::FloatRect enemyHitbox = (*ptr).sprite.getGlobalBounds(); // (x pos + xscale / 4, y pos , x scale / 2, y scale)
			//enemyHitbox = sf::FloatRect(enemyHitbox.left + enemyHitbox.width / 4, enemyHitbox.top, enemyHitbox.width / 2, enemyHitbox.height);
			//----------------------------------------------------------------------------


			if (rightHandWeapon.MeleeWeaponSprite.getGlobalBounds().intersects((*ptr).sprite.getGlobalBounds())) {
				attack(*petRockList[i], i);
			}
		}
	}
	else if (stage >= swingArc) {
		rightHandWeapon.MeleeWeaponSprite.setRotation(angle + (stage - 1));
		stage = 1;
		renderWindow.draw(rightHandWeapon.MeleeWeaponSprite);
		for (int i = 0; i < petRockList.size(); i++) {
			Character* ptr = petRockList.at(i).get();
			if (rightHandWeapon.MeleeWeaponSprite.getGlobalBounds().intersects((*ptr).sprite.getGlobalBounds())) {
				attack(*petRockList[i], i);
			}
		}
		attackTimer.restart();
		attackState = false;
		for (int i = 0; i < petRockList.size(); i++) {
			petRockList.at(i)->hit = false;
		}
	}
}

void Player::attack(Character& target, int indexOfTarget) {
	if (target.alive) {
		if (!target.hit) {
			int currentDamage = (strength / 2) + (rand() % strength + 1);
			currentDamage += rightHandWeapon.damage;
			if (currentDamage > strength) {
				//Yo Grant, here is where you can tell it to do critical display

				//This is my code, no touch...

				target.currentHealth -= currentDamage;

				target.hit = true;

				if (target.currentHealth <= 0) {
					score += 1;

					petRockList.erase(petRockList.begin() + indexOfTarget);
				}
			}
			else {
				//Yo Grant, here is where you can tell it to do a normal display

				//This is my code, no touch...

				target.currentHealth -= currentDamage;

				target.hit = true;

				if (target.currentHealth <= 0) {
					score += 1;

					petRockList.erase(petRockList.begin() + indexOfTarget);
				}
			}
		}
		else {

		}
	}
	else {

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

		//Movement checks here

		//float testAnimSpeed = 0.5f;

		//Movement
		sf::Vector2f movement(0, 0);

		sprite.setPosition(position.x, position.y);

		float deltaSpeed = dexterity * 35 * DeltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			movement.y += deltaSpeed;
			sprite.setTexture(playerForwardTex);
			animationSpeed = 0.2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement.x -= deltaSpeed;
			sprite.setTexture(playerLeftTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement.x += deltaSpeed;
			sprite.setTexture(playerRightTex);
			animationSpeed = 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			movement.y -= deltaSpeed;
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

		//Check Collision
		if (DoesCollide()) // if we collide with something
		{
			// undo the movement we just applied
			sprite.move(movement.x * -1, movement.y * -1);
		}
		//End of Check Collision

		renderWindow.draw(sprite);
		// End of all texture stuff

		//Doing Health Text
		healthText.setString("Health: " + std::to_string(currentHealth) + "/" + std::to_string(maxHealth));
		healthText.setPosition(renderWindow.mapPixelToCoords(sf::Vector2i(20, 0)));
		renderWindow.draw(healthText);
		//End of Health Text

		//Mouse Sensor
		if (attackState && attacked) {
			attackSFML(startingAngle);
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			attacked = false;
		}
		else if (!attackState && !attacked) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localPosition = sf::Mouse::getPosition(renderWindow);
				sf::Vector2f worldPosition = renderWindow.mapPixelToCoords(localPosition);
				currentAttackAngle = atan2(worldPosition.y - position.y, worldPosition.x - position.x) * 180 / PI;
				if (currentAttackAngle < 0) {
					currentAttackAngle = currentAttackAngle * -1;
				}
				else if (currentAttackAngle > 0) {
					currentAttackAngle = 360 - currentAttackAngle;
				}

				currentAttackAngle = -currentAttackAngle + 90;

				stage = 1;

				attackState = true;

				startingAngle = currentAttackAngle - swingArc / 2;

				attackSFML(startingAngle);
				attacked = true;
			}
		}
		else {

		}

		//console output
		//--------------------------------

		cout << "X: " << position.x << " Y: " << position.y << "\n";

		//--------------------------------


	}
		//End of Mouse Sensor
		
	else {
		
		//Death Text
		scoreText.setFont(asmanFont);
		scoreText.setString("Score " + std::to_string(score));
		scoreText.setCharacterSize(200);
		scoreText.setColor(sf::Color::Red);
		scoreText.setPosition(position.x-350, position.y-20);
		//End of Death Text

		
	}
}