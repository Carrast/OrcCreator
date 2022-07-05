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

	// testing
	HELLO hello1;
	HELLO hello2;

	hello1.x = 6;
	hello1.y = 4.5;
	hello2.x = 5;
	hello2.y = 6.5;


	bool eredmeny = Kisebb(3, 4);
	eredmeny = Kisebb(3.1, 3.3);
	eredmeny = Kisebb(3.1f, 3.3f);
	eredmeny = Kisebb(std::string("d"), std::string("x"));
	eredmeny = Kisebb(4.0f, 4.5f);
	eredmeny = Kisebb(hello1, hello2);
	eredmeny = false;
}

