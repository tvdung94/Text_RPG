#include<iostream>
#include "Hero.h"
using namespace std;

HERO::HERO(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
	int HP, int min_damage, int max_damage, double evade, int maxHP):Character(HP, min_damage, max_damage, evade, maxHP) {
	this->HP_bonus_per_lvl = HP_bonus_per_lvl;
	this->Damage_bonus_per_lvl = Damage_bonus_per_lvl;
	this->Evade_bonus_per_lvl = Evade_bonus_per_lvl;
	this->Lvlup_threshold = Lvlup_theshold;
	this->Current_gold = Current_gold;
}
HERO::~HERO() {
	delete this;
}

void HERO::update_current_gold(Monster &enemy) {
	this->Current_gold += enemy.Get_Gold_reward();
}
void HERO::update_current_xp(Monster &enemy) {
	this->Current_XP += enemy.Get_xp_reward();
}

bool HERO::lvl_up() {
	if (this->Current_XP >= this->Lvlup_threshold) {
		cout << "The hero is LVL UP !!" << endl;
		this->Set_maxHP(this->Get_maxHP() + this->HP_bonus_per_lvl);
		this->Current_XP = 0;
		this->Lvlup_threshold / 3 * 4 + 25;
		return true;
	}

	return false;
}