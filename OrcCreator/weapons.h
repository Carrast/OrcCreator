#pragma once
#include <string>

// abstract base class declaration
class Weapon {
public:
	Weapon(int d, std::string n) : damage(d), name_weapon(n), durability(100) { num_weapons++; }
	virtual ~Weapon() { num_weapons--; }
	virtual int Attack() = 0;
	virtual int GetDurability() const = 0;
	std::string GetName() const { return name_weapon; }
	int GetNumWeapons() const { return num_weapons; }

protected:
	std::string name_weapon;
	int damage;
	int durability;

private:
	static int num_weapons;
};

// sword
class Sword : public Weapon {
public:
	Sword() : Weapon(2, "sword") {}
	~Sword() {};
	int Attack() override;
	int GetDurability() const;

private:
};

// axe
class Axe : public Weapon {
public:
	Axe() : Weapon(3, "axe") {}
	~Axe() {};
	int Attack() override;
	int GetDurability() const;

private:
};

//class OneHandedAxe : public Axe {
//	OneHandedAxe() {}
//	~OneHandedAxe() {}
//};

// mace
class Mace : public Weapon {
public:
	Mace() : Weapon(5, "mace") {}
	~Mace() {}
	int Attack() override;
	int GetDurability() const;

private:
};

// bow
class Bow : public Weapon {
public:
	Bow() : Weapon(1, "bow"), range(5.3) {}
	~Bow() {}
	int Attack() override;
	int GetDurability() const;
	void SetRange(double r);

private:
	double range;
};

// testing
template <class T>
inline bool Kisebb(T a, T b) {
	if (b > a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
inline bool Kissebb(T a, T b) {
	if (b>a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

struct HELLO {
	int x;
	double y;
};

// specialised
template <>
inline bool Kisebb<HELLO>(HELLO a, HELLO b) {
	if (b.x > a.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//inline bool Kisebb(int a, int b) {
//	if (b>a)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//inline bool Kisebb(double a, double b) {
//	if (b>a)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}