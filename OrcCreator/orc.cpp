#include "orc.h"

// constructor
Orc::Orc(const std::string& name, int strength, int dexterity, int endurance) {
	its_name = name;
	its_strength = strength;
	its_dexterity = dexterity;
	its_endurance = endurance;

	// mutation
	is_mutated = false;

	// health - mana
	its_health = 30 + std::max(10, its_endurance) * 3;
	its_mana = 0;

	num_orcs++;
}

// destructor
Orc::~Orc() {
	std::cerr << "His body is destroyed.\n";
	num_orcs--;
}

// copy constructor
Orc::Orc(const Orc& other_orc) {
	its_name = other_orc.its_name;
	its_strength = other_orc.its_strength;
	its_dexterity = other_orc.its_dexterity;
	its_endurance = other_orc.its_endurance;
	its_intelligence = other_orc.its_intelligence;
	its_charisma = other_orc.its_charisma;

	// mutation
	is_mutated = other_orc.is_mutated;

	// health - mana
	its_health = other_orc.its_health;
	its_mana = other_orc.its_mana;
}

// class methods
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

void Orc::SetColor(std::string clr) {
	its_color = clr;
}

std::string Orc::GetColor() const {
	return its_color;
}

unsigned short Orc::GetNumOrcs() const {
	return num_orcs;
}

	// speech
void Orc::Roar(int intelligence, int charisma, std::string clr) {
	if (intelligence < 9)
	{
		std::cout << "ughm! ";
	}
	else if (intelligence < 12)
	{
		std::cout << "Aughm! die! ";
	}
	else if (intelligence < 15)
	{
		std::cout << "AArgHH! You die now! ";
	}
	else if (intelligence >= 15)
	{
		std::cout << "ARGH! You will die by my hand! ";
		std::cout << "My skin is " << clr << " ";
	}

	if (charisma > 14)
	{
		std::cout << "Ash-nazg Kratalatuk!!!";
	}

	std::cout << "\n\n";
}