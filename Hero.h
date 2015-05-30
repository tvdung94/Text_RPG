#ifndef Hero
#define Hero
#include "Chacracter.h"
#include "Monster.h"
class HERO: public Character
{
public:
	HERO(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
		int HP, int min_damage, int max_damage, double evade, int maxHP);
	~HERO();
	virtual void Deal_damage(Character &enemy) = 0;
	virtual void Take_damage(int damage) = 0;
	void update_current_gold(Monster &enemy);
	void update_current_xp(Monster &enemy);
	bool lvl_up();
private:
	int HP_bonus_per_lvl;
	int Damage_bonus_per_lvl;
	int Evade_bonus_per_lvl;
	int Current_XP;
	int Lvlup_threshold;
	int Current_gold;
};

#endif 