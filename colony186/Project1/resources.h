#include <string>
class resources
{
public:

	resources(){ re[0] = 1000; re[1] = 1000; re[2] = 1000; re[3] = 1000; re[4] = 1000; };
	void add(int x, int y){ re[x] += y; };
	void subtract(int x, int y){ re[x] -= y; };
	int get(int x){ return re[x]; };
	void set(int x, int y){ re[x] = y; };

	void write();


	void CInfo();
	void crabDrop();
	void mantisDrop();
	void mongerDrop();
private:
	int re[5];//0 = alloy, 1 = gem, 2 = nishati/energy, 3 = bone, 4 = research
};