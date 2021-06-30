#pragma once
#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(sf::RenderWindow& renderWindow, sf::Texture& texture, int xPos, int yPos, int length, bool hasCollider, bool bossSpawner, bool charSpawner, bool petRockSpawner);

	// variables
	sf::RenderWindow& renderWindow;
	sf::RectangleShape graphic;
	sf::Texture& texture;
	int length;
	int xPos;
	int yPos;
	bool hasCollider;
	bool bossSpawner;
	bool charSpawner;
	bool petRockSpawner;
	// functions
	void Update();

};
