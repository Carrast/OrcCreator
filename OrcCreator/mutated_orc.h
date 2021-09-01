#pragma once
#include <string>
#include "orc.h"

// derived class declaration
class MutatedOrc : public Orc {
public:
	int its_rage = 20;

	// constructor - destructor
	// using Orc::Orc;			// the easy solution
	MutatedOrc(const std::string& name, int strength, int dexterity, int endurance);
	virtual ~MutatedOrc();

	// mutated speech
	void Roar(int intelligence, int charisma, std::string its_color, int rage);
};