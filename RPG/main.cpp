#include "Stat.h"
#include <iostream>
#include "Actor.h"
#include <time.h>

int main() {
	srand(time(NULL));

	Actor player;
	std::cout << std::endl;
	std::cout << "Str: " << player.m_str.m_score << "\t" << player.m_str.m_bonus << std::endl;
	std::cout << "Int: " << player.m_int.m_score << "\t" << player.m_int.m_bonus << std::endl;
	std::cout << "Wis: " << player.m_wis.m_score << "\t" << player.m_wis.m_bonus << std::endl;
	std::cout << "Cha: " << player.m_cha.m_score << "\t" << player.m_cha.m_bonus << std::endl;
	std::cout << "Dex: " << player.m_dex.m_score << "\t" << player.m_dex.m_bonus << std::endl;
	std::cout << "Con: " << player.m_con.m_score << "\t" << player.m_con.m_bonus << std::endl;
	std::cout << "AC: " << player.m_armor_class << std::endl;
	std::cout << "HP: " << player.m_HP_max << std::endl;
	std::getchar();
	return 0;
}