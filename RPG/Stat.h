#pragma once
#include <math.h>

class Stat {
public:
	Stat();
	Stat(const int& score);
	~Stat();
	void update(const int& modifier);
	int m_score;
	int m_bonus;

private:
	void calcBonus();
};