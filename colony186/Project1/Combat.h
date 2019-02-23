#include <string>


class combatObject{
public:


	combatObject(){
		//Default Constructor, sets stats to lowest functioning val
		set_Name("CombatObject");
		set_MaxHp(0);
		set_curHp(0);
		set_atkRange(0, 0);
		set_armor(0);
		set_isBlocking(false);
		set_isAlive(false);
	}

	combatObject(std::string a, int b, int c, int d, int e, bool f, bool g, int h){
		//Constructor for Enemy, sets vals by arguments
		set_Name(a);
		set_MaxHp(b);
		set_curHp(b);
		set_atkRange(c, d);
		set_armor(e);
		set_isBlocking(f);
		set_isAlive(g);
		accuracy = h;
	}

	combatObject(std::string a, int b, int c, int d, int e, bool f, bool g, int h, int i, int j, int k, int l) {
		//Constructor for player, sets vals by arguments

		set_Name(a);
		set_MaxHp(b);
		set_curHp(b);
		set_atkRange(c, d);
		set_armor(e);
		set_isBlocking(f);
		set_isAlive(g);
		player_Tools[0] = h;
		player_Tools[1] = i;
		player_Tools[2] = j;
		player_Tools[3] = k;
		player_Tools[4] = 0;
		player_Tools[5] = 0;
		player_Tools[6] = 0;
		accuracy = 80;
		set_critChance(l);
		energyAtkCost = 3;
		energyGain = 2;
	}

	//accessor
	std::string get_Name(){ return name; }
	int get_MaxHp(){ return maxHp; }
	int get_curHp(){ return curHp; }
	int get_atkMin(){ return atk_Min; }
	int get_atkMax(){ return atk_Max; }
	int get_armor(){ return armor; }
	int get_isBlocking(){ return isBlocking; }
	int get_isAlive(){ return isAlive; }
	bool get_Acc();//return wether the an attack hit or not
	int get_critChance(){ return critChance; };
	int get_atkCost(){ return energyAtkCost; };
	int get_recover(){ return energyGain; };


	int get_maxEnergy(){
		return player_Tools[1];
	};
	void increase_maxEnergy(int val){
		player_Tools[1] += val;
		player_Tools[2] = player_Tools[1];
	};
	int get_curEnergy(){
		return player_Tools[2];
	};
	void reduce_curEnergy(int cost){
		player_Tools[2] -= cost;
	};
	int increase_curEnergy(int val){
		int cur = get_curEnergy();
		int max = get_maxEnergy();
		int diff = max - cur;

		if (diff >= val)
		{
			player_Tools[2] += val;
			return val;
		}
		else
		{
			player_Tools[2] += diff;
			return diff;
		}
	};
	int use_GPotion(){
		int num = get_Potions();
		int curHp = get_curHp();
		int maxHp = get_MaxHp();
		int diff = maxHp - curHp;
		player_Tools[4] -= 1;

		if (diff >= 40)
		{
			set_curHp(curHp + 40);
			return 20;
		}
		else if (diff < 40)
		{
			set_curHp(curHp + diff);
			return diff;
		}
		return 0;
	};
	int get_Potions(){
		return player_Tools[3];
	}
	int use_Potion(){
		int num = get_Potions();
		int curHp = get_curHp();
		int maxHp = get_MaxHp();
		int diff = maxHp - curHp;
		player_Tools[3] -= 1;
	
		if (diff >= 20)
		{
			set_curHp(curHp + 20);
			return 20;
		}
		else if (diff < 20)
		{
			set_curHp(curHp + diff);
			return diff;
		}
		return 0;
	}

	//mutator
	void set_Name(std::string x){ name = x; }
	void set_MaxHp(int x){ maxHp = x; }
	void set_curHp(int x){ curHp = x; }
	void set_atkRange(int x, int y){ atk_Min = x; atk_Max = y; }
	void set_armor(int x){ armor = x; }
	void set_isBlocking(bool x){ isBlocking = x; }
	void set_isAlive(bool x){ isAlive = x; }
	void set_critChance(int x){ critChance = x; }
	void steps(bool);
	void set_acc(int x){ accuracy += x; }
	void awali_buff(bool x);
	void blood_buff(bool x);
	void set_atkCost(int x){ energyAtkCost += x; };
	void set_recover(int x){ energyGain += x; };

	//cheats
	void cheat();

	int player_Tools[7];//0 = Resources, 1 = Max Energy, 2 = Cur Energy, 3 = Potions, 4 = greater potion, 5 = awali ale, 6 = monster blood
	bool buffs[2];//0 = awali ale, 1 = monster blood

private:
	std::string name;
	int maxHp;
	int curHp;
	int atk_Min;
	int atk_Max;
	int armor;
	bool isBlocking;
	bool isAlive;
	int accuracy;
	int critChance;
	int energyAtkCost;
	int energyGain;
};


void set_potions(int x, int y);

void buildEnemyLibrary();



void increase_maxEnergy();



void increase_Potions(int val);


void reduce_curHp(int val);


void increase_maxHp(int val);

void reset(std::string name, int b, int c, int d, int e, bool f, bool g, int h, int i, int j, int k);

bool combatObject::get_Acc()
{
	int temp = rand() % 100 + 1;
	if (temp <= accuracy)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void combatObject::awali_buff(bool x)
{
	if (x == true)
	{
		player_Tools[5] -= 1;
		buffs[0] = true;
		set_armor(get_armor() + 2);
		set_atkRange(get_atkMin() + 1, get_atkMax() + 1);
		set_acc(-10);
		player_Tools[1] -= 3;
		if (player_Tools[1] > player_Tools[2])
		{
			player_Tools[2] = player_Tools[1];
		}
	}
	else if (x == false && buffs[0] == true)
	{
		buffs[0] = false;
		set_armor(get_armor() - 2);
		set_atkRange(get_atkMin() - 1, get_atkMax() - 1);
		set_acc(+10);
		player_Tools[1] += 3;
	}
}

void combatObject::blood_buff(bool x)
{
	if (x == true)
	{
		player_Tools[6] -= 1;
		buffs[1] = true;
		set_armor(get_armor() + 1);
		set_atkRange(get_atkMin() + 1, get_atkMax() + 1);
		set_critChance(get_critChance() - 5);
	}
	else if (x == false && buffs[1] == true)
	{
		buffs[1] = false;
		set_armor(get_armor() - 1);
		set_atkRange(get_atkMin() - 1, get_atkMax() - 1);
		set_critChance(get_critChance() - 5);
		if (player_Tools[1] > player_Tools[2])
		{
			player_Tools[2] = player_Tools[1];
		}
	}
}

void combatMain();


const int cPPos = 50;//change player position
const int cEPos = 100;//change enemy position
const int y = 0;//used to offset the y coordinates of combat down.

//0 = Resources, 1 = Max Energy, 2 = Cur Energy 3 = Potions, 4 greater potion, 5, awali ale, 6, monster blood
//awali ale, 1 = monster blood
//enemy status effects.




