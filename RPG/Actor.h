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
	Stat m_str;
	Stat m_int;
	Stat m_wis;
	Stat m_con;
	Stat m_dex;
	Stat m_cha;
	
	Class m_class;
	Race m_race;
	ArmorType m_equipped_armor;
	
	int m_armor_class;
	int m_spell_save_dc;
	int m_HP_max;
	int m_HP_curr;
	int m_level;
	int m_hit_die;

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
	void classMod();
	void backgroundMod();
};

