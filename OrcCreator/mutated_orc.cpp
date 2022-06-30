#include "mutated_orc.h"

// constructor
MutatedOrc::MutatedOrc(const std::string& name, int strength, int dexterity, int endurance) : Orc(name, strength, dexterity, endurance) {
	its_name = name;
	its_strength = strength;
	its_dexterity = dexterity;
	its_endurance = endurance;

	// mutation
	is_mutated = true;

	// health - mana
	its_health = 30 + std::max(10, its_endurance) * 3;
	its_mana = 0;
}

// destructor
MutatedOrc::~MutatedOrc() {
	std::cerr << "His mutated body is destroyed.\n";
}

// mutated speech
void MutatedOrc::Roar(int intelligence, int charisma, std::string clr, int rage) {
	std::cout << "I AM URUK-HAI!! ";
	std::cout << "My skin is " << clr << "! ";
	std::cout << "I am angry! My rage is " << rage << "!\n\n";
}