#pragma once

#include <string>

// class declaration
class Orc {
public:
	std::string its_name;
	int its_strength = 0;
	int its_dexterity = 0;
	int its_endurance = 0;
	int its_health = 0;
	int its_mana = 20;
	int its_kills = 0;

	// constructor - destructor
	Orc(const std::string& name, int strength, int dexterity, int endurance);
	~Orc();

	// copy constructor
	Orc(const Orc& other_orc);

	void SetIntelligence(int intelligence);
	int GetIntelligence() const;
	void SetCharisma(int charisma);
	int GetCharisma() const;

	// speech
	void Roar(int intelligence, int charisma);

private:
	int its_intelligence = 0;
	int its_charisma = 0;
};
