#pragma once

// class declaration
class Orc {
public:
	std::string its_name;
	int its_strength = 0;
	int its_dexterity = 0;
	int its_endurance = 0;
	int its_health = 0;

	// constructor - destructor
	Orc(std::string name, int strength, int dexterity, int endurance);
	~Orc();

	void SetIntelligence(int intelligence);
	int GetIntelligence() const;
	void SetCharisma(int charisma);
	int GetCharisma() const;

	// speech
	void Roar(int intelligence, int charisma);

private:
	int its_intelligence = 0;
	int its_charisma = 0;

protected:
	int its_mana = 20;
};

// constructor
Orc::Orc(std::string name, int strength, int dexterity, int endurance) {
	its_name = name;
	its_strength = strength;
	its_dexterity = dexterity;
	its_endurance = endurance;

	// health
	its_health = its_endurance * 3;
}

// destructor
Orc::~Orc() {

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