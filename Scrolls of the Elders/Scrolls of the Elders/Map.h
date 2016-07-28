#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

#include "Tile.h"

class Map
{
public:
	// constructors
	Map(sf::RenderWindow& renderWindow, int tileSize, sf::Texture& floor, sf::Texture& charSpawner, sf::Texture& bossSpawner, sf::Texture&petRockSpawner, sf::Texture& wall, sf::Image &layout);
	
	// variables
	std::vector<Tile> tiles;
	sf::RenderWindow& renderWindow;
	sf::Texture& floor;
	sf::Texture& charSpawner;
	sf::Texture& bossSpawner;
	sf::Texture& petRockSpawner;
	sf::Texture& wall;

	// functions
	void Update();
};

