#include "Actor.h"

void Actor::attack(Actor & target) {
	
}

Actor::Actor() {
	m_equipped_armor = NONE;
	
	///TEST VALUES
	m_level = 20;
	m_class = FIGHTER;
	m_race = DWARF;
	///

	getHitDice();
	rollStats();
	raceMod();
	calcAC();
	initHP();
}

Actor::~Actor() {
}

int Actor::rollStat() {
	int roll[4];
	
	for(int x = 0; x < 4; ++x) {
		roll[x] = Die::roll(6);
		std::cout << roll[x] << " ";
	}
	
	int* low = &roll[0];
	
	for(int x = 1; x < 4; ++x) {
		if(roll[x] < *low)
			swap(roll[x], *low);
	}
	
	int sum = *low = 0;
	
	for(int x = 0; x < 4; ++x) {
		sum += roll[x];
	}
	std::cout << "Sum: " << sum << std::endl;
	return sum;
}

void Actor::swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void Actor::initHP() {
	//Max hp at level 1
	m_HP_max = m_hit_die;

	//Roll additional hit dice if starting at a level higher than 1
	for(int x = 1; x < m_level; ++x) {
		m_HP_max += rollHP();
	}
}

int Actor::rollHP() {
	int roll = (Die::rollSum(Die::roll(1, m_hit_die)));
	if(roll < (m_hit_die / 2))
		roll = (m_hit_die / 2) + 1;
	return roll + m_con.m_bonus;
}

void Actor::getHitDice() {
	switch(m_class){
		case FIGHTER:
			m_hit_die = 10;
			break;
		case WIZARD:
			m_hit_die = 6;
			break;
		case CLERIC:
		case ROGUE:
		default:
			m_hit_die = 8;
			break;
	}
}

void Actor::calcAC() {
	switch(m_equipped_armor) {
		case NONE:
			m_armor_class = 10 + m_dex.m_bonus;
			break;
		case LEATHER:
		case PADDED:
			m_armor_class = 11 + m_dex.m_bonus;
			break;
		case STUDDED:
		case HIDE:
			m_armor_class = 12 + m_dex.m_bonus;
			break;
		case CHAIN_SHIRT:
			m_armor_class = 13 + m_dex.m_bonus;
			break;
		case SCALE_MAIL:
		case BREASTPLATE:
			m_armor_class = 14 + m_dex.m_bonus;
			break;
		case HALF_PLATE:
			m_armor_class = 15 + m_dex.m_bonus;
			break;
		case RING_MAIL:
			m_armor_class = 14;
			break;
		case PLATE:
			m_armor_class = 18;
			break;
		case CHAIN_MAIL:
			m_armor_class = 16;
			break;
		case SPLINT:
			m_armor_class = 17;
			break;
		default:
			m_armor_class = 10 + m_dex.m_bonus;
	}
}

void Actor::raceMod() {
	switch(m_race) {
		case HUMAN:
			m_str.update(1);
			m_int.update(1);
			m_wis.update(1);
			m_dex.update(1);
			m_con.update(1);
			m_cha.update(1);
			break;
		case ELF:
			m_dex.update(2);
			break;
		case DWARF:
			m_con.update(2);
			break;
		case GNOME:
			m_int.update(2);
			break;
		case HALFLING:
			m_dex.update(2);
			break;
	}
}

void Actor::rollStats() {
	m_str = Stat(rollStat());
	m_int = Stat(rollStat());
	m_wis = Stat(rollStat());
	m_con = Stat(rollStat());
	m_dex = Stat(rollStat());
	m_cha = Stat(rollStat());
}
