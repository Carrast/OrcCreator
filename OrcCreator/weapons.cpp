#include "weapons.h"

int Sword::Attack() {
	return damage;
}

int Sword::GetDurability() const {
	return durability;
}

int Axe::Attack() {
	return damage;
}

int Axe::GetDurability() const {
	return durability;
}

int Mace::Attack() {
	return damage;
}

int Mace::GetDurability() const {
	return durability;
}

int Bow::Attack() {
	return damage;
}

int Bow::GetDurability() const {
	return durability;
}

void Bow::SetRange(double r) {
	range = r;
}

