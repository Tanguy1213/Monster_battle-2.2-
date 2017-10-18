#include "Monster.h"
#include <iostream>


float Monster::getHealth()
{
	return health;
}

float Monster::getSpeed()
{
	return speed;
}

Monster::Monster(sf::Texture& Orc_texture, sf::Texture& Goblin_texture,Race race)
{
	do
	{
		if (race == 1)
		{
			std::cout << "You're an Orc !\n";

			if (!Orc_texture.loadFromFile("../data/orc_zumbi.png"))
			{
			}
			Sprite.setTexture(Orc_texture);
			Sprite.setScale(-5.f, 5.f);
			Sprite.setPosition(320.f, 270.f);
		}

		if (race == 2)
		{
			std::cout << "You're a Goblin !\n";
			if (!Goblin_texture.loadFromFile("../data/Goblin.png"))
			{
			}
			Sprite.setTexture(Goblin_texture);
			Sprite.setScale(0.63f, 0.63f);
			Sprite.setPosition(290.f, 200.f);
			Sprite.getRotation();
		}
		

	} while (race <= 0 || race > 2);

	std::cout << "Then, enter the stats of your monster ( HP, AP, DP, S ):\n";

	std::cout << "HP : "; std::cin >> this->health;
	std::cout << "AP : "; std::cin >> this->attackPower;
	std::cout << "DP : "; std::cin >> this->defensivePower;
	std::cout << "S : "; std::cin >> this->speed;
	std::cout << "\n";
}


Monster::~Monster()
{
}

sf::Sprite Monster::getSprite()
{
	return Sprite;
}


void Monster::attack(Monster& opponent)
{
	
	double damages = this->attackPower - opponent.defensivePower;
	if (damages <= 0)
		damages = 1;
	opponent.health -= damages;

}

void Monster::draw_monster(sf::RenderWindow & window)
{
	window.draw(Sprite);
}
