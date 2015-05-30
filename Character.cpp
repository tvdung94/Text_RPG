#include <iostream>
#include "Chacracter.h"
using namespace std;

Character::Character(int HP, int min_damage, int max_damage, double evade, int maxHP) {
	this->HP = HP;
	this->maxHP = maxHP;
	this->min_damage = min_damage;
	this->max_damage = max_damage;
	this->evade = evade;
}

Character::~Character() {
	delete this;
}

void Character::Set_stunned(bool boolean) {
	this->stunned = boolean;
}

bool Character::Get_stunned() {
	return stunned;
}
void Character::Set_HP(int change) {
	this->HP -= change;
}



int Character::Get_min_damage() {
	return this->min_damage;
}

int Character::Get_max_damage() {
	return this->max_damage;
}

double Character::Get_evade() {
	return this->evade;
}

void Character::Set_maxHP(int maxHP) {
	this->maxHP = maxHP;
}

int Character::Get_maxHP() {
	return maxHP;
}

int Character::GetHP() {
	return HP;
}