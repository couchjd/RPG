#pragma once
#include "Stat.h"
#include "Die.h"
#include <iostream>
#include <math.h>

enum ArmorType {
	NONE,
	LEATHER,
	PADDED,
	STUDDED,
	HIDE,
	BREASTPLATE,
	HALF_PLATE,
	CHAIN_SHIRT,
	SCALE_MAIL,
	RING_MAIL,
	PLATE,
	CHAIN_MAIL,
	SPLINT
};

enum Race {
	HUMAN,
	ELF,
	DWARF,
	GNOME,
	HALFLING
};

enum Class {
	FIGHTER,
	CLERIC,
	WIZARD,
	ROGUE
};

class Actor {
public:
	Stat* strength;
	Stat* intelligence;
	Stat* wisdom;
	Stat* constitution;
	Stat* dexterity;
	Stat* charisma;
	
	Class ch_class;
	Race race;
	ArmorType armor;
	
	int AC;
	int DC;
	int HP_max;
	int HP_curr;
	int level;
	int hit_die;

	void attack(Actor& target);
	Actor();
	~Actor();

private:
	int rollStat();
	void rollStats();
	void swap(int& a, int& b);
	void initHP();
	int rollHP();
	void getHitDice();
	void calcAC();
	void raceMod();
};

