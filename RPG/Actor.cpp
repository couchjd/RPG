#include "Actor.h"

void Actor::attack(Actor & target) {
	
}

Actor::Actor() {
	armor = NONE;
	
	///TEST VALUES
	level = 20;
	ch_class = FIGHTER;
	race = DWARF;
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
	HP_max = hit_die;

	//Roll additional hit dice if starting at a level higher than 1
	for(int x = 1; x < level; ++x) {
		HP_max += rollHP();
	}
}

int Actor::rollHP() {
	int roll = (Die::rollSum(Die::roll(1, hit_die)));
	if(roll < (hit_die / 2))
		roll = (hit_die / 2) + 1;
	return roll + constitution->m_bonus;
}

void Actor::getHitDice() {
	switch(ch_class){
		case FIGHTER:
			hit_die = 10;
			break;
		case WIZARD:
			hit_die = 6;
			break;
		case CLERIC:
		case ROGUE:
		default:
			hit_die = 8;
			break;
	}
}

void Actor::calcAC() {
	switch(armor) {
		case NONE:
			AC = 10 + dexterity->m_bonus;
			break;
		case LEATHER:
		case PADDED:
			AC = 11 + dexterity->m_bonus;
			break;
		case STUDDED:
		case HIDE:
			AC = 12 + dexterity->m_bonus;
			break;
		case CHAIN_SHIRT:
			AC = 13 + dexterity->m_bonus;
			break;
		case SCALE_MAIL:
		case BREASTPLATE:
			AC = 14 + dexterity->m_bonus;
			break;
		case HALF_PLATE:
			AC = 15 + dexterity->m_bonus;
			break;
		case RING_MAIL:
			AC = 14;
			break;
		case PLATE:
			AC = 18;
			break;
		case CHAIN_MAIL:
			AC = 16;
			break;
		case SPLINT:
			AC = 17;
			break;
		default:
			AC = 10 + dexterity->m_bonus;
	}
}

void Actor::raceMod() {
	switch(race) {
		case HUMAN:
			strength->update(1);
			intelligence->update(1);
			wisdom->update(1);
			dexterity->update(1);
			constitution->update(1);
			charisma->update(1);
			break;
		case ELF:
			dexterity->update(2);
			break;
		case DWARF:
			constitution->update(2);
			break;
		case GNOME:
			intelligence->update(2);
			break;
		case HALFLING:
			dexterity->update(2);
			break;
	}
}

void Actor::rollStats() {
	strength = new Stat(rollStat());
	intelligence = new Stat(rollStat());
	wisdom = new Stat(rollStat());
	constitution = new Stat(rollStat());
	dexterity = new Stat(rollStat());
	charisma = new Stat(rollStat());
}
