#include <iostream>
#include <ctime>
#include "Game_mechanics.h"
#include "Chacracter.h"
#include "Hero.h"
#include "Caster.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Monster.h"
#include "Map.h"
using namespace std;

int main() {
	srand(time(NULL));
	Character *p;
	Character *m;
	Map *map = new Map();
	do {// Choose Character Loop
		int n;
		cout << "Choose character: 1. Warrior 2. Rogue 3. Caster" <<endl;
		cin >> n;
		switch (n)
		{
		case 3 :
			cout << "Choose Caster" << endl;
			p = new Caster(18, 3, 0.02, 50, 0, 75, 12, 18, 0.15, 75);
			break;
		case 2 :
			cout << "Choose Rogue" << endl;
			p = new Rogue(15, 4, 0.05, 50, 0, 55, 20, 35, 0.4, 55);
			break;
		case 1 :
		default:
			cout<<"Choose default: Warrior"<<endl;
			p = new Warrior(25, 2, 0.02, 50, 0, 100, 10, 20, 0.2, 100);
			break;
		}
		// Game loop
		int move;
		while (true) {
			cout << "Current position: " << map->getPosX() << " " << map->getPosY() << endl;
			cout << "Go: 1. Left 2. Right 3. Up 4. Down" << endl;
			cin >> move;
			switch (move) {
			case 1:
				map->setPosXY(-1, 0); 
				break;
			case 2:
				map->setPosXY(1, 0);
				break;
			case 3:
				map->setPosXY(0, 1);
				break;
			case 4:
				map->setPosXY(0, -1);
				break;
			}
			if (TriggerEffect(0.3)) {
				cout << "You encounter a monster!!" << endl;
				m =new  Monster(100, 10, 11, 0.1, 100, 25, 25);
				int action;
				while (true) {
					cout << "Hero's HP: " << p->GetHP() << "/" << p->Get_maxHP() << endl;
					cout << "Monster's HP: " << m->GetHP() << "/" << m->Get_maxHP() << endl;
					cout << "Your turn: 1. Attack 2. Run" << endl;
					cin >> action;
					switch (action) {
					case 1:
						p->Deal_damage(*m);
						break;
					case 2:
						goto game_continue;
						break;
					}
					if (m->GetHP() <= 0)
						goto reward_state;
					
					cout << "Hero's HP: " << p->GetHP() << "/" << p->Get_maxHP() << endl;
					cout << "Monster's HP: " << m->GetHP() << "/" << m->Get_maxHP() << endl;
					if (m->Get_stunned()) {
						cout << "The Monster has been stunned" << endl;
						m->Set_stunned(false);
					}
					else {
						m->Deal_damage(*p);
						if (p->GetHP() <= 0)
							goto game_over;
					}
				}
			}
			if (false) {
			reward_state:
				cout << "You defeated the monster" << endl;
				HERO *h = (HERO*)p;
				Monster *mo = (Monster*)m;
				cout << "You got " << mo->Get_xp_reward() << " XP and " << mo->Get_Gold_reward() << " golds" << endl;
				if (h->lvl_up())
					cout << "You got lvl up!!" << endl;
			}
			if (false) {
			game_continue:
				cout << "You just ran away" << endl;
			}
		}
			//Fight loop
	game_over:
		char c;
		cout << "You are dead!!" << endl;
		cout << "Playing again? (Y/y)" << endl;
		cin >> c;
		if (c != 'Y') exit(0);
	} while (true);
	return 0;
}
