#include "Die.h"

Die::Die() {
}

Die::~Die() {
}

int Die::roll(int sides) {
	return rand() % sides + 1;
}

std::vector<int> Die::roll(const int& num, const int& sides) {
	std::vector<int> rolls;
	for(int x = 0; x < num; ++x) {
		rolls.push_back(roll(sides));
	}
	return rolls;
}

int Die::rollSum(const std::vector<int>& rolls) {
	int sum = 0;
	for(auto& n : rolls)
		sum += n;
	return sum;
}
