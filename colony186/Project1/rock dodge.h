class rocks{
public:
	rocks(){
		y = 1;
	}
	~rocks(){
	}
	int getx();
	int gety();
	void setInitial(int);
	void fall();
private:
	int x;
	int y;


};
int rocks::getx(){
	return x;
}
int rocks::gety(){
	return y;
}
void rocks::setInitial(int position){
	x = position;
}
void rocks::fall(){
	if (y < 9){
		y++;
	}
	else{
		y = rand() % 3;
		x = rand() % 9;
	}
}