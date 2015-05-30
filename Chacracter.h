#ifndef CHARACTER
#define CHARACTER
class Character
{

protected: bool stunned;
public:
	 Character(int HP, int min_damage, int max_damage, double evade, int maxHP);
	~Character();
	int Get_min_damage();
	int Get_max_damage();
	double Get_evade();
	void Set_stunned(bool boolean);
	bool Get_stunned();
	void Set_HP(int change);
	int Get_maxHP();
	int GetHP();
	void Set_maxHP(int maxHP);
	virtual void Deal_damage(Character &enemy) = 0;
	virtual void Take_damage(int damage) = 0;

private:
	int HP;
	int maxHP;
	int min_damage;
	int max_damage;
	double evade;
};

#endif