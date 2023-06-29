#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Spell {
public:
	int power;
	int mana;

	Spell(int power, int mana) : power(power), mana(mana) {}
};

bool operator<(const Spell& lhs, const Spell& rhs) {
	return lhs.mana < rhs.mana;
}

struct Combination {
	bool operator()(const Spell& lhs, const Spell& rhs) {
		if (lhs.power == rhs.power) {
			return lhs.mana > rhs.mana;
		}
		return lhs.power < rhs.power;
	}
};

int main() {
	vector<Spell> spells;
	spells.emplace_back(Spell(10, 5));
	spells.emplace_back(Spell(5, 10));
	spells.emplace_back(Spell(7, 8));
	spells.emplace_back(Spell(7, 5));

	sort(spells.begin(), spells.end());
	cout << "mana sort:" << endl;
	for (const auto& spell : spells) {
		cout << "power: " << spell.power << ", mana: " << spell.mana << endl;
	}

	sort(spells.begin(), spells.end(), Combination());
	cout << "mana sort:" << endl;
	for (const auto& spell : spells) {
		cout << "power: " << spell.power << ", mana: " << spell.mana << endl;
	}

	return 0;
}