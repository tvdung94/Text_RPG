#include <iostream>
#include "Caster.h"
using namespace std;

Caster::Caster(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
	int HP, int min_damage, int max_damage, double evade, int maxHP) :HERO(HP_bonus_per_lvl, Damage_bonus_per_lvl, Evade_bonus_per_lvl, Lvlup_theshold,
	Current_gold, HP, min_damage, max_damage, evade, maxHP) {}

Caster::~Caster() {
	delete this;
}

void Caster::Deal_damage(Character &enemy) {
	// Implement after done with all character classes
	int raw_damage = randomDamage(this->Get_min_damage(), this->Get_max_damage());
	if (TriggerEffect(fire)) {
		raw_damage += 40;
		cout << "The mage has attacked with fire ball for " << raw_damage << " damage!!" << endl;
		enemy.Take_damage(raw_damage);
		return;
	}
	if (TriggerEffect(ice)) {
		raw_damage += 10;
		enemy.Take_damage(raw_damage);
		enemy.Set_stunned(true);
		cout << "The mage has attacked with ice ball for " << raw_damage << " damage!!" << endl;
		return;

	}
}

void Caster::Take_damage(int damage) {
	// Implement afer done with all character classes
	if (TriggerEffect(this->Get_evade())) {
		cout << "The caster has evaded the attack!!" << endl;
		this->Set_HP(0);
		return;
	}
	this->Set_HP(damage);
}
