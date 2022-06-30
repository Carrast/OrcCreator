#pragma once
#include "orc.h"
#include <string>
#include <iostream>

// derived class declaration
class MutatedOrc : public Orc {
public:
	int its_rage = 20;

	// constructor - destructor
	// using Orc::Orc;			// the easy solution
	MutatedOrc(const std::string& name, int str, int dex, int end);
	virtual ~MutatedOrc();

	// mutated speech
	void Roar(int intelligence, int charisma, std::string clr, int rage);
};