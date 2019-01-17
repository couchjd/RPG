#include "Race.h"

Race::Race() {
}

Race::Race(const RaceEnum & _race) {
	switch(_race) {
		case HUMAN:
			str_mod = 1;
			int_mod = 1;
			wis_mod = 1;
			con_mod = 1;
			dex_mod = 1;
			cha_mod = 1;
			darkvision = false;
			languages = {COMMON};	//Choose one more
			break;

		case DWARF:
			str_mod = 0;
			int_mod = 0;
			wis_mod = 0;
			con_mod = 2;
			dex_mod = 0;
			cha_mod = 0;
			darkvision = true;
			languages = {COMMON, DWARVISH};
			break;

		case ELF:
			str_mod = 0;
			int_mod = 0;
			wis_mod = 0;
			con_mod = 0;
			dex_mod = 2;
			cha_mod = 0;
			darkvision = true;
			languages = {COMMON, ELVISH};
			break;

		case HALFLING:
			str_mod = 0;
			int_mod = 0;
			wis_mod = 0;
			con_mod = 0;
			dex_mod = 2;
			cha_mod = 0;
			darkvision = false;
			languages = {COMMON, HALFLING_L};
			break;

		case HALF_ELF:		//Increase 2 others by 1
			str_mod = 0;
			int_mod = 0;
			wis_mod = 0;
			con_mod = 0;
			dex_mod = 0;
			cha_mod = 2;
			add_stats(2);
			darkvision = true;
			languages = {COMMON, ELVISH};
			break;

		case GNOME:
			str_mod = 0;
			int_mod = 2;
			wis_mod = 0;
			con_mod = 0;
			dex_mod = 0;
			cha_mod = 0;
			darkvision = true;
			languages = {COMMON, GNOMISH};
			break;
	}
}

Race::~Race() {
}

void Race::add_stats(const int & num_stats) {
	for(int x = 0; x < num_stats; ++x) {
		int stat;
		std::cout << "1) Strength" << std::endl;
		std::cout << "2) Intelligence" << std::endl;
		std::cout << "3) Wisdom" << std::endl;
		std::cout << "4) Constitution" << std::endl;
		std::cout << "5) Dexterity" << std::endl;
		std::cout << "6) Charisma" << std::endl;
		std::cout << "Select a stat to increase: ";
		std::cin >> stat;

		switch(stat) {
			case 1:
				str_mod += 1;
				break;
			case 2:
				int_mod += 1;
				break;
			case 3:
				wis_mod += 1;
				break;
			case 4:
				con_mod += 1;
				break;
			case 5:
				dex_mod += 1;
				break;
			case 6:
				cha_mod += 1;
				break;
			default:
				break;
		}
	}
}
