#pragma once
#include "Player.h"
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>

class Spheres
{
public:
	Spheres(sf::RenderWindow &renderWindow, Character &player, float &DeltaTime, sf::Vector2f &position);
	sf::Vector2f &position;
	float &DeltaTime;
	sf::RenderWindow &renderWindow;
	Character &player;
	void Follow();
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect textureRect[4];
	sf::Clock clock;
	int textureInt = 0;
	bool alive;
	float time;
	~Spheres();
};

