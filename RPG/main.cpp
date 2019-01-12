#include "Stat.h"
#include <iostream>
#include "Actor.h"
#include <time.h>

int main() {
	srand(time(NULL));

	Actor player;
	std::cout << std::endl;
	std::cout << "Str: " << player.strength->m_score << "\t" << player.strength->m_bonus << std::endl;
	std::cout << "Int: " << player.intelligence->m_score << "\t" << player.intelligence->m_bonus << std::endl;
	std::cout << "Wis: " << player.wisdom->m_score << "\t" << player.wisdom->m_bonus << std::endl;
	std::cout << "Cha: " << player.charisma->m_score << "\t" << player.charisma->m_bonus << std::endl;
	std::cout << "Dex: " << player.dexterity->m_score << "\t" << player.dexterity->m_bonus << std::endl;
	std::cout << "Con: " << player.constitution->m_score << "\t" << player.constitution->m_bonus << std::endl;
	std::cout << "AC: " << player.AC << std::endl;
	std::cout << "HP: " << player.HP_max << std::endl;
	std::getchar();
	return 0;
}