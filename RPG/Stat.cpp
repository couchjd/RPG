#include "Stat.h"

Stat::Stat() {
}

Stat::Stat(const int & score) : m_score(score) {
	calcBonus();
}

Stat::~Stat() {
}

void Stat::update(const int& modifier) {
	m_score += modifier;
	calcBonus();
}

void Stat::calcBonus() {
	m_bonus = (m_score - 10) / 2;
}
