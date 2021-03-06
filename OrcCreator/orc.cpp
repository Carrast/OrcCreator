#include "orc.h"

// constructor
Orc::Orc(const std::string& name, int str, int dex, int end) {
	its_name = name;
	strength = str;
	dexterity = dex;
	endurance = end;

	// mutation
	is_mutated = false;

	// health - mana
	health = 30 + std::max(10, endurance) * 3;
	mana = 0;

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
	strength = other_orc.strength;
	dexterity = other_orc.dexterity;
	endurance = other_orc.endurance;
	intelligence = other_orc.intelligence;
	charisma = other_orc.charisma;

	// mutation
	is_mutated = other_orc.is_mutated;

	// health - mana
	health = other_orc.health;
	mana = other_orc.mana;
}

// class methods
void Orc::SetIntelligence(int intel) {
	intelligence = intel;
}

int Orc::GetIntelligence() const {
	return intelligence;
}

void Orc::SetCharisma(int cha) {
	charisma = cha;
}

int Orc::GetCharisma() const {
	return charisma;
}

void Orc::SetColor(std::string clr) {
	color = clr;
}

std::string Orc::GetColor() const {
	return color;
}

unsigned short Orc::GetNumOrcs() const {
	return num_orcs;
}

	// speech
void Orc::Roar(int intel, int cha, std::string clr) {
	if (intel < 9)
	{
		std::cout << "ughm! ";
	}
	else if (intel < 12)
	{
		std::cout << "Aughm! die! ";
	}
	else if (intel < 15)
	{
		std::cout << "AArgHH! You die now! ";
	}
	else if (intel >= 15)
	{
		std::cout << "ARGH! You will die by my hand! ";
		std::cout << "My skin is " << clr << " ";
	}

	if (cha > 14)
	{
		std::cout << "Ash-nazg Kratalatuk!!!";
	}

	std::cout << "\n\n";
}