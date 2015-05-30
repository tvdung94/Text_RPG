#include <iostream>
#include "Rogue.h"
#include "Game_mechanics.h"
using namespace std;

Rogue::Rogue(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
	int HP, int min_damage, int max_damage, double evade, int maxHP) :HERO(HP_bonus_per_lvl, Damage_bonus_per_lvl, Evade_bonus_per_lvl, Lvlup_theshold,
	Current_gold, HP, min_damage, max_damage, evade, maxHP) {}

Rogue::~Rogue() {
	delete this;
}

void Rogue::Deal_damage(Character &enemy) {
	// Implement after done with all character classes
	int damage = randomDamage(this->Get_min_damage(), this->Get_max_damage());
	if (TriggerEffect(this->Crit)) {
		cout << "The Rogue has just done a 4.5x critical strike!!" << endl;
		damage = damage * 1.5;
		enemy.Take_damage(damage);
		return;
	}
}

void Rogue::Take_damage(int damage) {
	// Implement afer done with all character classes
	if (!TriggerEffect(this->Get_evade()))
		this->Set_HP(damage);
	else
		cout << "The Rogue has evaded the attack!" << endl;
}