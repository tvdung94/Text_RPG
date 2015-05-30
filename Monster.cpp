#include <iostream>
#include "Monster.h"

using namespace std;

Monster::Monster(int HP, int min_damage, int max_damage, double evade, int maxHP, int XP_reward, int Gold_reward) :
Character(HP, min_damage, max_damage, evade, maxHP) {
	this->XP_reward = XP_reward;
	this->Gold_reward = Gold_reward;
}

Monster::~Monster() {
	delete this;
}

int Monster::Get_xp_reward() {
	return XP_reward;
}

int Monster::Get_Gold_reward() {
	return Gold_reward;
}

void Monster::Deal_damage(Character &enemy) {
	int raw_damage = randomDamage(this->Get_min_damage(), this->Get_max_damage());
	cout << "Monster attack!!" << endl;
	enemy.Take_damage(raw_damage);
}

void Monster::Take_damage(int damage) {
	this->Set_HP(damage);
}