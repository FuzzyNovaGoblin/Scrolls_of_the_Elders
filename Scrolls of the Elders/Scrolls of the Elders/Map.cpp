#include "Map.h"
#include <iostream>

// helper function to forive colors that are not exact in layout image
bool ColorsEqual(sf::Color a, sf::Color b) {

	int deltaR = std::abs(a.r - b.r);
	int deltaG = std::abs(a.g - b.g);
	int deltaB = std::abs(a.b - b.b);

	int error = 70; // the error allowed when seeing if two colors are equal: rgb (0-255)

	if (deltaR <= error && deltaG <= error && deltaB <= error) 
	{
		return true;
	}
	else return false;
}

Map::Map(sf::RenderWindow& renderWindow, int tileSize, sf::Texture& brick, sf::Texture& grass, sf::Texture& dirt, sf::Texture& water, sf::Image &layout) : renderWindow(renderWindow) , floor(brick), charSpawner(grass), bossSpawner(dirt), wall(water)
{
	
	 // the image which we will use to generate our background map from

	int width = layout.getSize().x;
	int height = layout.getSize().y;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			sf::Color pixel = layout.getPixel(x, y);
			int xPos = x * tileSize; // determine the x position coordinate
			int yPos = y * tileSize; // determine the y position coordinate
			// figure out which background tile to create
			if (ColorsEqual(pixel, sf::Color::Red)) {
				// red is for brick
				Tile tile(renderWindow, floor, xPos, yPos, tileSize, false, false, false);
				tiles.push_back(tile);
			}
			else if (ColorsEqual(pixel, sf::Color::Green)) {
				// green is for grass
				Tile tile(renderWindow, charSpawner, xPos, yPos, tileSize, false, false, true);
				tiles.push_back(tile);
			}
		
			else if (ColorsEqual(pixel, sf::Color::Blue)) {
				// blue is for dirt/ sand currently
				Tile tile(renderWindow, bossSpawner, xPos, yPos, tileSize, false, true, false);
				tiles.push_back(tile);
			}
			else {
				// default (nothing) is water
				Tile tile(renderWindow, wall, xPos, yPos, tileSize, true, false, false);
				tiles.push_back(tile);
			}
		}
	}
}

void Map::Update() {
	for (int i = 0; i < tiles.size(); i++) {
		tiles.at(i).Update();
	}
}
