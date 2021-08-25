#include "orc.h"
#include <iostream>

Orc::Orc(const std::string& name, int strength, int dexterity, int endurance) {
	its_name = name;
	its_strength = strength;
	its_dexterity = dexterity;
	its_endurance = endurance;

	// health
	its_health = its_endurance * 3;
}

// destructor
Orc::~Orc() {
	std::cout << "His body is destroyed.\n";
}

void Orc::SetIntelligence(int intelligence) {
	its_intelligence = intelligence;
}

int Orc::GetIntelligence() const {
	return its_intelligence;
}

void Orc::SetCharisma(int charisma) {
	its_charisma = charisma;
}

int Orc::GetCharisma() const {
	return its_charisma;
}

void Orc::Roar(int intelligence, int charisma) {
	if (intelligence < 9)
	{
		std::cout << "argh!\n";
	}
	else if (intelligence < 12)
	{
		std::cout << "AArgHH!\n";
	}
	else if (intelligence < 15)
	{
		std::cout << "Aughm! You die now!\n";
	}
	else if (intelligence >= 15)
	{
		std::cout << "AArghh! You will die by my hand!\n";
	}

	if (charisma > 16)
	{
		std::cout << "Ash-nazg Kratalatuk!!!\n";
	}
}