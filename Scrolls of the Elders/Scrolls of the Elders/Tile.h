#pragma once
#include <SFML\Graphics.hpp>
class Tile
{
public:
	Tile(sf::RenderWindow& renderWindow, sf::Texture& texture, int xPos, int yPos, int length, bool hasCollider);

	// variables
	sf::RenderWindow& renderWindow;
	sf::RectangleShape graphic;
	sf::Texture& texture;
	int length;
	int xPos;
	int yPos;
	bool hasCollider;

	// functions
	void Update();

};

