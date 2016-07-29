#include "PetRock.h"



PetRock::PetRock(int inputHealth, sf::RenderWindow& renderWindow, sf::Texture& petRockTex, Character& player, float& DeltaTime, Map &map) : Character(DeltaTime, map), renderWindow(renderWindow), petRockTex(petRockTex), player(player)
{

	petRockSkin[0] = sf::IntRect(0, 0, 40, 28);
	petRockSkin[1] = sf::IntRect(0, 28, 40, 28);
	petRockSkin[2] = sf::IntRect(0, 56, 40, 28);
	
	currentHealth = inputHealth;

	strength = 4;

	hit = false;


	for (int i = 0; i < map.tiles.size(); i++) {
		if (map.tiles.at(i).petRockSpawner) {
			
			/*tempX= map.tiles.at(i).xPos;
			tempY= map.tiles.at(i).yPos;*/

			spawnPositions.push_back(sf::Vector2f (map.tiles.at(i).xPos + rand() % 100 +0, map.tiles.at(i).yPos));
		}
	}




	/*float tempX = rand() % 2000 + 0;
	float tempY = rand() % 2000 + 0;

	position.x = tempX;
	position.y = tempY; 
*/
	/*int num = spawnPositions.size();

	int point = rand() % spawnPositions.size() + 0;*/



	sprite.setPosition(spawnPositions[rand() % spawnPositions.size() + 0]);

	sprite.setTexture(petRockTex);
	
	timer = clock.getElapsedTime().asSeconds();
	sprite.setOrigin(20, 14);

}


void PetRock::move() {
	int distanceX = position.x - player.position.x;
	int distanceY = position.y - player.position.y;
	position = sprite.getPosition();
	if (sqrt(distanceX * distanceX + distanceY * distanceY) < 500) {
		
		//float deltaDistance = speed *DeltaTime; // the amout of pixels to move per second in one axis

		sf::Vector2f movement(0, 0);

		float deltaSpeed = DeltaTime * 350;

			if (position.x > player.position.x+50 ) {
				movement.x -= deltaSpeed;
			}
			if (position.x < player.position.x - 50) {
				movement.x += deltaSpeed;
			}
			if (position.y < player.position.y + 40) {
				movement.y += deltaSpeed;
			}
			if (position.y > player.position.y+20) {
				movement.y -= deltaSpeed;
			}

			sprite.move(movement);
			//if you want to colide
			//-----------------------------------------------------
			//if (DoesCollide()) // if we collide with something
			//{
			//	// undo the movement we just applied
			//	sprite.move(movement.x * -1, movement.y * -1);
			//}
			//-----------------------------------------------------

			
		
	}
}

void PetRock::attack() {

	if (position.x > player.position.x - 51 && position.x < player.position.x + 51 && position.y > player.position.y && position.y < player.position.y + 42) {
		sf::Vector2f movement(0, 0);

		if (attackTime.getElapsedTime().asSeconds() > 1) {
	
			int damage = (strength / 2) + (rand() % strength + 1);
			player.currentHealth -= damage;

			attackTime.restart();

		}

	}
}

void PetRock::Update() {
	if (alive) {
		
		if (currentHealth <= 0) {
			alive = false;
		}
		attack();
		move();

		if (clock.getElapsedTime().asSeconds() > 0.5) {
			if (petRockSkinInt == 0) {
				petRockSkinInt = 1;
			}
			else {
				petRockSkinInt = 0;
			}
			clock.restart();
		}

		sprite.setTextureRect(sf::IntRect(petRockSkin[petRockSkinInt]));
		renderWindow.draw(sprite);
	}


}