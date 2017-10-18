#ifndef MONSTER_H
#define MONSTER_H
#include "SFML\Graphics.hpp"

enum Race
{
	Orc = 1,
	Goblin = 2
};

class Monster
{
private :

	double health = 0.;
	double attackPower = 0.;
	double defensivePower = 0.;
	double speed = 0.;

public:
	float getHealth();
	float getSpeed();
	Monster(sf::Texture& Orc_texture, sf::Texture& Goblin_texture,Race race);
	~Monster();

	sf::Sprite getSprite();

	void attack(Monster& opponent);
	void draw_monster(sf::RenderWindow&  window);

	sf::Sprite Sprite;
	sf::Text damage_text;
	Race race;
};
#endif
