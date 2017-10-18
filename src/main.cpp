#include <SFML\Graphics.hpp>
#include <iostream>
#include "Monster.h"
#define LOWEST_MONSTER_HEALTH 0

void show_screen(sf::RenderWindow& window,sf::Sprite& background, Monster monster1,Monster monster2)
{
	window.clear();
	window.draw(background);
	monster1.draw_monster(window);
	monster2.draw_monster(window);
	window.display();
}

int main()

{
	int round = 0;
	const int window_height = 600;
	const int window_width = 800;
	const float frame_rate_limit = 60.0f;
	
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "MONSTER BATTLE SOMULATOR");
	window.setFramerateLimit(frame_rate_limit);
	
	sf::Texture background_texture;
	if (!background_texture.loadFromFile("../data/Background.png"))
	{}
	sf::Sprite background(background_texture);


	sf::Texture Orc_sprite;
	sf::Texture Troll_sprite;
	sf::Texture Goblin_sprite;
	

	Monster monster1 = Monster(Orc_sprite,Goblin_sprite,Orc);
	Monster monster2 = Monster(Orc_sprite,Goblin_sprite, Goblin);

	show_screen(window, background, monster1, monster2);

	bool is_monster1_attacking;

	if (monster1.getSpeed() > monster2.getSpeed())
	{
		is_monster1_attacking = true;
	}

	else
	{
		is_monster1_attacking = false;
	}

	while (window.isOpen())
	{
		sf::Clock clock;
		sf::Time elapsed;

		while (elapsed.asSeconds() != 1.f)
		{
			elapsed = clock.getElapsedTime();
		}

		

			while (elapsed.asSeconds() != 2.f)
			{
				elapsed = clock.getElapsedTime();
			}

	
				round += 1;

				if (is_monster1_attacking == true)
				{
					monster2.getSprite().setPosition(290.f, 200.f);
					monster1.attack(monster2);
					monster1.getSprite().setPosition(500.f, 270.f);
		
					
				}

				else
				{
					monster1.getSprite().setPosition(320.f, 270.f);
					monster2.attack(monster1);
					monster2.getSprite().setPosition(50.f, 200.f);

				}

				is_monster1_attacking = !is_monster1_attacking;
	
		if (monster1.getHealth() <= 0)
		{
			std::cout << "The winner is the Goblin" << " and the fight lasted "<< round <<" round." << "\n";
			break;
		}
		if (monster2.getHealth() <= 0)
		{
			std::cout << "The winner is the Orc" << " and the fight lasted " << round << " round." << "\n";
			break;
		}

		show_screen(window, background, monster1, monster2);
		
	}
	system("pause");
	return EXIT_SUCCESS;
}