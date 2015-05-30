#include <stdlib.h>
#include <iostream>
using namespace std;
int randomDamage(int min_damage, int max_damage) {
	int range = max_damage - min_damage;
	int result = rand() % range + min_damage;
	return result;
}

bool TriggerEffect(double factor) {
	//cout << rand() % 100 << endl;
	if (rand() % 100 <= (int)(factor * 100))
		return true;
	else
		return false;
}