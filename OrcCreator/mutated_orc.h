#pragma once
#include <string>
#include "orc.h"

class MutatedOrc : public Orc {
public:
	int its_rage = 0;

	// mutated speech
	void Roar(int intelligence, int charisma);
};