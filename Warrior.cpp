#include <iostream>
#include "Warrior.h"
#include "Game_mechanics.h"
using namespace std;

Warrior::Warrior(int HP_bonus_per_lvl, int Damage_bonus_per_lvl, int Evade_bonus_per_lvl, int Lvlup_theshold, int Current_gold,
int HP, int min_damage, int max_damage, double evade, int maxHP) :HERO(HP_bonus_per_lvl,  Damage_bonus_per_lvl, Evade_bonus_per_lvl,  Lvlup_theshold,
Current_gold, HP, min_damage, max_damage, evade, maxHP) {}

Warrior::~Warrior() {
	delete this;
}

void Warrior::Deal_damage(Character &enemy) {
	// Implement after done with all character classes
	int damage = randomDamage(this->Get_min_damage(), this->Get_max_damage());
	if (TriggerEffect(this->Crit)) {
		cout << "The warrior has just done a 1.5x critical strike!!" << endl;
		damage = damage * 1.5;
		enemy.Take_damage(damage);
		return;
	}
	if (TriggerEffect(this->Bash)) {
		cout << "The warrior has just bashed the enemy!!" << endl;
		enemy.Take_damage(damage);
		return;
	}
}

void Warrior::Take_damage(int damage) {
	// Implement afer done with all character classes
	if (TriggerEffect(this->Get_evade())) {
		cout << "The Warrior has evaded the attack" << endl;
		this->Set_HP(0);
	}
	if (TriggerEffect(this->Block)) {
		cout << "The Warrior has blocked the attack"<< endl;
		damage = damage / 2;
		this->Set_HP(damage);
		return;
	}
	this->Set_HP(damage);
}