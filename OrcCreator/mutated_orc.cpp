#include "mutated_orc.h"

// constructor
MutatedOrc::MutatedOrc(const std::string& name, int str, int dex, int end) : Orc(name, str, dex, end) {
	its_name = name;
	strength = str;
	dexterity = dex;
	endurance = end;

	// mutation
	is_mutated = true;

	// health - mana
	health = 30 + std::max(10, endurance) * 3;
	mana = 0;
}

// destructor
MutatedOrc::~MutatedOrc() {
	std::cerr << "His mutated body is destroyed.\n";
}

// mutated speech
void MutatedOrc::Roar(int intel, int cha, std::string clr, int rage) {
	std::cout << "I AM URUK-HAI!! ";
	std::cout << "My skin is " << clr << "! ";
	std::cout << "I am angry! My rage is " << rage << "!\n\n";
}