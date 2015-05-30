#ifndef CASTER
#define CASTER
#include "Hero.h"
#include "Game_mechanics.h"
class Caster :public HERO {
public: Caster(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
	int HP, int min_damage, int max_damage, double evade, int maxHP);
		~Caster();
		void Deal_damage(Character &enemy);
		void Take_damage(int damage);
		
private:
	const double fire = 0.4;
	const double ice = 0.4;
};
#endif