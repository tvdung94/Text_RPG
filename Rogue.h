#ifndef ROGUE
#include "Hero.h"
class Rogue :public HERO {
public: Rogue(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
	int HP, int min_damage, int max_damage, double evade, int maxHP);
		~Rogue();
		void Deal_damage(Character &enemy);
		void Take_damage(int damage);
private:
	const double Crit = 0.5;
};
#endif