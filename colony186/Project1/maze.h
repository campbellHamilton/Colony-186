#include <vector>
#include <string>

const int size = 24;//this the max size of the maze. note that since this runs through an algorithm the actual size is different.


class mazes
{
public:

	std::string biome;
	mazes(int, int, int);
	void make(std::string);
	void setup();
	void writen(std::string);
	void Write(std::string);
	void Write2();
	int move();

	void random();
	bool check(bool &exit);
	void reRandom(int);
	void cave(bool);
	void setCave(int x, int y);
	void rType(int, int);
	bool combatChance(int &combat);
	void setRes(int res[], int &research);
	void getRes(int res[], int &research);
	void moveWrite();
	void moveWrite2();

	short rSize; //this is the size of the map array
	int pos[2];//pos[0] = x, pos[1] = y
	std::vector<std::string> line;
	bool visit[size * 2 - 1][size * 2 - 1];

	void nextBiome(int);

	int colour;

	int getMax(){ return max; };
	void setMax(int setter) { max = setter; };

private:
	int re[5]; // 
	
	int sizex;
	int sizey;
	bool maze[size][size];
	bool wall[size][size];
	bool floor[size][size];
	int directions[size*size];//this is the the square of the size of the arrays
	int place = 0;
	int max = 8;
	
	bool cType;
};

