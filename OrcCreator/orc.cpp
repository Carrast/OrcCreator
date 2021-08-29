#include "orc.h"
#include <iostream>

// constructor
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

// copy constructor
Orc::Orc(const Orc& other_orc) {
	its_name = other_orc.its_name;
	its_strength = other_orc.its_strength;
	its_dexterity = other_orc.its_dexterity;
	its_endurance = other_orc.its_endurance;

	// health
	its_health = other_orc.its_endurance * 3;
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

void Orc::SetColor(std::string clr) {
	its_color = clr;
}

std::string Orc::GetColor() {
	return its_color;
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