#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

#include "Tile.h"

class Map
{
public:
	// constructors
	Map(sf::RenderWindow& renderWindow, int tileSize, sf::Texture& brick, sf::Texture& grass, sf::Texture& dirt, sf::Texture& water);
	
	// variables
	std::vector<Tile> tiles;
	sf::RenderWindow& renderWindow;
	sf::Texture& brick;
	sf::Texture& grass;
	sf::Texture& dirt;
	sf::Texture& water;
	// functions
	void Update();
};

