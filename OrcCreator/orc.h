#pragma once
#include <string>
#include <iostream>

// class declaration
class Orc {
public:
	std::string its_name;
	int strength;
	int dexterity;
	int endurance;
	int health;
	int mana;

	int level = 1;
	bool is_mutated = false;
	int	experience;
	int num_kills;

	// constructor - destructor
	Orc(const std::string& name, int str, int dex, int end);
	virtual ~Orc();

	// copy constructor
	Orc(const Orc& other_orc);

	// functions
	void SetColor(std::string clr);
	std::string GetColor() const;

	void SetIntelligence(int intelligence);
	int GetIntelligence() const;
	void SetCharisma(int cha);
	int GetCharisma() const;
	unsigned short GetNumOrcs() const;

	// speech
	virtual void Roar(int intel, int cha, std::string color);

protected:
	std::string its_color = "green";

private:
	int its_intelligence = 0;
	int its_charisma = 0;
	static unsigned short num_orcs;
};
