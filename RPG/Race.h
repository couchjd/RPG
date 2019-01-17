#pragma once
#include "Languages.h"
#include <vector>
#include <iostream>

enum RaceEnum {
	HUMAN,
	DWARF,
	ELF,
	HALFLING,
	HALF_ELF,
	GNOME
};

class Race {
public:
	int str_mod = 0;
	int int_mod = 0;
	int wis_mod = 0;
	int con_mod = 0;
	int dex_mod = 0;
	int cha_mod = 0;
	
	std::vector<Languages> languages;
	bool darkvision = false;

	Race();
	Race(const RaceEnum& _race);
	~Race();

private:
	void add_stats(const int& num_stats);
};

