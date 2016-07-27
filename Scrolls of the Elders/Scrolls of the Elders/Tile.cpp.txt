#include "Tile.h"

Tile::Tile(sf::RenderWindow& renderWindow, sf::Texture& texture, int xPos, int yPos, int length, bool hasCollider) : renderWindow(renderWindow), texture(texture)
{
	this->length = length;
	this->hasCollider = hasCollider;
	this->xPos = xPos;
	this->yPos = yPos;
	graphic.setTexture(&texture);
	graphic.setSize(sf::Vector2f(length, length));
	graphic.setPosition(xPos, yPos);
}


void Tile::Update() {
	renderWindow.draw(graphic);
}