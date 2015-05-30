#ifndef MONSTER
#define MONSTER
#include "Chacracter.h"
#include "Game_mechanics.h"
class Monster : public Character {
public: Monster(int HP, int min_damage, int max_damage, double evade, int maxHP, int XP_reward, int Gold_reward);
		~Monster();
		void Deal_damage(Character &enemy);
		void Take_damage(int damage);
		int Get_xp_reward();
		int Get_Gold_reward();
private: 
	int XP_reward;
	int Gold_reward;
};
#endif