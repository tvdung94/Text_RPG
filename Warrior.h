#ifndef WARRIOR
#define WARRIOR
#include "Hero.h"
class Warrior: public HERO
{
public:
	Warrior(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
		int HP, int min_damage, int max_damage, double evade, int maxHP);
	~Warrior();
	
	void Deal_damage(Character &enemy);
	void Take_damage(int damage);
private:
	double Block = 0.4;
	double Bash = 0.3;
	double Crit = 0.2;
};


#endif