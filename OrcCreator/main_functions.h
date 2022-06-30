#pragma once
#include <iostream>
#include <vector>
#include "orc.h"
#include "mutated_orc.h"

// main functions
void WelcomeText();
void ShowOptions();

// main functions to create orcs in heap
Orc* CreateOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma);
MutatedOrc* CreateMutatedOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma);
void ListOrcs(const int number_orcs, const std::vector<Orc*>& orcs);