#pragma once
#include <random>

class Die {
public:
	~Die();
	static int roll(int sides);
	static std::vector<int> roll(const int& num, const int& sides);
	static int rollSum(const std::vector<int>& rolls);
private:
	Die();
};

